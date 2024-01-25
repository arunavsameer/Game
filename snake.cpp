#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

#define KB_UP 72
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_DOWN 80
#define HEIGHT 20
#define WIDTH 40

//look for better approach than clear screen and printing due to cursor movment... and add time interval for refreshing the screen
//add the fruit logic and score system

class game{
    char board[HEIGHT][WIDTH];
    deque <pair <int, int>> snake;
    int dir = KB_LEFT;
    bool gameOver = false;
    int score = 0;

public:    
    void reset_board(){
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                board[i][j] = ' ';
            }
        }
    }

    void start_game(){
        snake.push_front(make_pair(10, 10));
        snake.push_back(make_pair(10, 9));  
        snake.push_back(make_pair(10, 8));
    }

    void take_input(){
        if (_kbhit()){
            switch (_getch())
            {
            case KB_LEFT:
                dir = KB_LEFT;
                break;
            case KB_RIGHT:
                dir = KB_RIGHT;
                break;
            case KB_UP:
                dir = KB_UP;
                break;
            case KB_DOWN:
                dir = KB_DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    void move_snake(){
        switch (dir){
            case KB_UP:
                int new_first;
                if(snake.at(0).first == 0){
                    new_first = HEIGHT - 1;
                }else{
                    new_first = snake.at(0).first - 1;
                }

                snake.push_front(make_pair(new_first, snake.at(0).second));
                break;

            case KB_DOWN:
                snake.push_front(make_pair((snake.at(0).first + 1) % HEIGHT, snake.at(0).second));
                break;

            case KB_RIGHT:
                snake.push_front(make_pair(snake.at(0).first, (snake.at(0).second) + 1 % WIDTH));
                break;

            case KB_LEFT:
                snake.push_front(make_pair(snake.at(0).first, (snake.at(0).second - 1) % WIDTH));
                break;

            default:
                break;
        }
        snake.pop_back();
    }

    void print_board(){
        for(auto i : snake){
            board[i.first][i.second] = '#';
        }
        for(int i = 0; i < WIDTH + 2; i++){
            cout << '-';
        }
        cout << endl;
        for(int i = 0; i < HEIGHT; i++){
            cout << '=';
            for(int j = 0; j < WIDTH; j++){
                cout << board[i][j];
            }
            cout << '=';
            cout << endl;
        }
        for(int i = 0; i < WIDTH + 2; i++){
            cout << '-';
        }
    }
};

int main(){
    game g;
    g.reset_board();
    g.start_game();
    while(1){
        g.print_board();
        g.take_input();
        g.move_snake();
        g.reset_board();
        system("cls");
    }
}
