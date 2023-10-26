#include <bits/stdc++.h>
using namespace std;

char board[3][3];
char winner = ' ';

void ResetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
    winner = ' ';
}

void PrintBoard(){
    cout << board[0][0] <<" | " <<board[0][1]<<" | "<<board[0][2]<<endl;
    cout << "--+---+--"<<endl;
    cout << board[1][0] <<" | " <<board[1][1]<<" | "<<board[1][2]<<endl;
    cout << "--+---+--"<<endl;
    cout << board[2][0] <<" | " <<board[2][1]<<" | "<<board[2][2]<<endl; 
}

int CheckFreeSpaces(){
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                count++;
            }
        }
    }
    return count;
}

void PlayerMove(){
    cout << "Your Turn: " <<endl;
    bool flag = false;
    do{
        int row, column;
        cout << "Enter the Row(1-3): "; cin >> row;
        cout << "Enter the Column(1-3): "; cin >> column;
        if(board[row - 1][column - 1] != ' '){
            cout << "Enter a Valid Move!" <<endl;
            flag = true;
        }else{
            board[row - 1][column - 1] = 'X';
            flag = false;
        }
    }while(flag);
}

void ComputerMove(){
    cout << "Computer's Turn: " <<endl;
    bool flag = false;
    do{
        int row, column;
            row = rand() % 3;
            column = rand() % 3;
        if(board[row][column] != ' '){
            flag = true;
        }else{
            board[row][column] = 'O';
            flag = false;
        }
    }while(flag);
}

bool CheckWinner(){
    bool ans = false;
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
            ans = true;
            winner = board[i][0];
            break;
        }else if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
            ans = true;
            winner = board[0][i];
            break;
        }
    }
    if(!ans){
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
            ans = true;
        }else if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' '){
            ans = true;
        }
        if(ans){
            winner = board[1][1];
        }
    }
    return ans;
}

void PrintWinner(){
    if(winner == ' '){
        cout << "Tie" <<endl;
    }else if(winner == 'X'){
        cout << "You Win!" <<endl;
    }else{
        cout << "Computer Wins!" <<endl;
    }
}

int main(){
    ResetBoard();
    while(CheckFreeSpaces() != 0){
        if(CheckFreeSpaces() % 2 == 0){
            PlayerMove();
        }else{
            ComputerMove();
        }
        if(CheckWinner()){
            break;
        }
        PrintBoard();
    }
    PrintBoard();
    PrintWinner();
}



