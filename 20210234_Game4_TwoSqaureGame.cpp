// Cairo University
// Faculty of Computer Science and Artifial Intelligence
// CS112 - structured programming
// assignment 1 
// name: abdallah hassan abdallah
// id : 20210234
// two square game - game 4 
// #############################

// importing some libraries to get some help 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// ///////////////////////////
// create board 
string board[16] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16"};

// //////////////////////
// display the board to user 
// | 01 | 02 | 03 | 04 |
// | 05 | 06 | 07 | 08 |
// | 09 | 10 | 11 | 12 |
// | 13 | 14 | 15 | 16 |


void display_board(){
    
    cout << "  ------------------- " << endl;
    for (int i = 0; i < 4; i++){
        cout << " | " << board[i*4] << " | " << board[i*4+1] << " | " << board[i*4+2] << " | " << board[i*4+3] << " | " << endl;
        cout << "  ------------------- " << endl;
    }
}
// //////////////////////////
// take inputs from user and check if it is valid or not

vector<int> get_action(string player) {
    int x,y;
    vector<int> action;
    bool is_valid = false;
    while (!is_valid){
        cout << player <<" please enter 2 'valid' nums from 1 to 16" <<endl;
        cin >> x >> y;
        action.push_back(x);
        action.push_back(y);
        is_valid = 17 > action[0] > 0 && 17 > int(action[1]) > 0 ;
        is_valid = is_valid && board[action[0]-1] != " x" && board[action[1]-1] != " x";
        if (action[0] < action[1]){
            if (action[0] % 4 == 0){
                is_valid = is_valid && abs(action[0] - action[1]) == 4;
            }else{
                is_valid = is_valid && (abs(action[0] - action[1]) == 1 || abs(action[0] - action[1]) == 4);
            }
        }else{
            if (action[1] % 4 == 0){
                is_valid = is_valid && abs(action[0] - action[1]) == 4;
            }else{
                is_valid = is_valid && (abs(action[0] - action[1]) == 1 || abs(action[0] - action[1]) == 4);
            }
        }
    }
    return action;
}
// ///////////////////////////////////////////////
// replace every square that player chose by "x" 

void update_game_board(vector<int> action,string symboll){
    board[action[0] - 1] = symboll;
    board[action[1] - 1] = symboll;
    display_board();
}
// //////////////////////////////////////////
// check if there is a winner or not 

bool is_winner(){
    vector<int> not_chosen;
    vector<bool> flag;
    if (count(board , board + 16 , " x") >= 12){
        for(int i = 0; i < 16 ;i++){
            if (board[i] != " x"){
                not_chosen.push_back(i);
            }
        }
        for(int y = 0; y < (not_chosen.size())-1; y++){
            if (abs(not_chosen[y] - not_chosen[y+1]) == 1 or abs(not_chosen[y] - not_chosen[y+1]) == 4){
                flag.push_back(false);
            
            }else{
                flag.push_back(true);
            }
        }
        if (count(flag.begin(),flag.end(),false)){
            return false;
        }else{
            return true;
        }
    }else{
        return false;
    }
    
}
// ///////////////////////////////////////
// main function  

int main() {
    // Write C++ code here
    int n_actions = 0;
    vector<int> action;
    display_board();
    while (n_actions != 8){
        action = get_action("player1");
        update_game_board(action, " x" );
        if (is_winner()){
            cout << "player1 wins" << endl;
            _Exit(0);
        }
        n_actions +=1 ; 
        
        
        action = get_action("player2");
        update_game_board(action, " x" );
        if (is_winner()){
            cout << "player2 wins" << endl;
            _Exit(0);
        }
        n_actions +=1 ;
        
    }
    cout << "player2 wins" << endl;

    return 0;
}