# Cairo University
# Faculty of Computer Science and Artifial Intelligence
# CS112 - structured programming
# assignment 1 
# name: abdallah hassan abdallah
# id : 20210234
# two square game - game 4 
# ########################

board = ["01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16"]
#########################
# display the board to user 
# | 01 | 02 | 03 | 04 |
# | 05 | 06 | 07 | 08 |
# | 09 | 10 | 11 | 12 |
# | 13 | 14 | 15 | 16 |
  
def display_board():
    print("  ------------------- ")
    for i in range(0,4):
        print(" | " + board[i*4] + " | " + board[i*4+1] + " | " + board[i*4+2] + " | " + board[i*4+3] + " | ")
        print("  ------------------- ")


#########################
# take inputs from user and check if it is valid or not

def get_action(player):
    is_valid = False 
    message = player + " enter 2 'valid' nums from 1 to 16: " 
    while not is_valid :  
        action = input(message).strip("").split()        
        is_valid = 17 > int(action[0]) > 0 and 17 > int(action[1]) > 0 
        is_valid = is_valid and board[int(action[0])-1] != " x" and board[int(action[1])-1] != " x"
        if int(action[0]) < int(action[1]):
            if int(action[0]) % 4 == 0:
                is_valid = is_valid and abs(int(action[0]) - int(action[1])) == 4
            else:
                is_valid = is_valid and (abs(int(action[0]) - int(action[1])) == 1 or abs(int(action[0]) - int(action[1])) == 4)
        else:
            if int(action[1]) % 4 == 0:
                is_valid = is_valid and abs(int(action[0]) - int(action[1])) == 4
            else:
                is_valid = is_valid and (abs(int(action[0]) - int(action[1])) == 1 or abs(int(action[0]) - int(action[1])) == 4)
    return action


####################################
# replace every square that player chose by "x" 

def update_game_board(action, symboll):
    board[int(action[0]) - 1] = symboll
    board[int(action[1]) - 1] = symboll
    display_board()
    

###########################
# check if there is a winner or not 

def is_winner():
    not_chosen = []
    flag = []
    if board.count(" x") >= 12: 
        for i in range(16):
            if board[i] != " x":
                not_chosen.append(i)
            
        for y in range(len(not_chosen)-1):
            if abs(not_chosen[y] - not_chosen[y+1]) == 1 or abs(not_chosen[y] - not_chosen[y+1]) == 4:
                flag.append(False)
            else:
                flag.append(True)
        
        if False in flag:
            return False
        else:
            return True
            
    else:
        return False
    
        
            

##########################
# main function  

def play_game():
    display_board()
    n_action = 0
    while n_action != 8 :
        action = get_action("player1")
        update_game_board(action, " x" )
        if is_winner():
            print("player1 wins")
            exit()
        n_action += 1

        action = get_action("player2")
        update_game_board(action , " x")
        if is_winner():
            print("player2 wins")
            exit()
        n_action += 1
    print("player2 wins")    
###########################
# calling functions 

play_game()
