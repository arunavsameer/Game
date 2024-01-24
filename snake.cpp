#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

#define KB_UP 72
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_DOWN 80

//use a deque or a vector to store the data of the snake... remove the last and add to the head (vector/deque <pair <int, int>>)... no need of pair head and tail
//look for better approach than clear screen and printing due to cursor movment... and add time interval for refreshing the screen
//try to make the board squareish...

class game{
    char board[20][20];
    pair<int, int> head;
    pair<int, int> tail;
    int direction = KB_RIGHT;

public:    
    void reset_board(){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                board[i][j] = ' ';
            }
        }
    }

    void start_game(){
        board[10][10] = '#';
       // board[10][11] = '#';
        head = make_pair(10, 10);
        //tail = make_pair(10, 10);
    }

    void move_snake(){
        if(kbhit){
            direction = getch();
        }
        switch (direction){
            case KB_UP:
                int new_first;
                if(head.first == 0){
                    new_first = 19;
                }else{
                    new_first = head.first - 1;
                }

                board[head.first][head.second] = ' ';
                board[new_first][head.second] = '#';
                head = make_pair((new_first), head.second);
            break;

            case KB_DOWN:
                board[head.first][head.second] = ' ';
                board[(head.first + 1) % 20][head.second] = '#';
                head = make_pair(((head.first + 1) % 20), head.second);                 
            break;

            case KB_RIGHT:
                board[head.first][head.second] = ' ';
                board[head.first][(head.second + 1) % 20] = '#';  
                head = make_pair(head.first, ((head.second + 1) % 20));      
            break;

            case KB_LEFT:
                board[head.first][head.second] = ' ';
                board[head.first][(head.second - 1) % 20] = '#';
                head = make_pair(head.first, ((head.second - 1) % 20));                    
            break;

            default:
                break;
        }     
    }

    void print_board(){
        cout << "----------------------";
        cout << endl;
        for(int i = 0; i < 20; i++){
            cout << '=';
            for(int j = 0; j < 20; j++){
                cout << board[i][j];
            }
            cout << '=';
            cout << endl;
        }
        cout << "----------------------";
    }
};



int main(){
    game g;
    g.reset_board();
    g.start_game();
    while(1){
        g.print_board();
        g.move_snake();
        system("cls");
    }
}