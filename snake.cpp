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

//try to add time interval 

class game{
    char board[HEIGHT][WIDTH];
    deque <pair <int, int>> snake;
    int dir = KB_RIGHT;
    int score = 0;

public:    
    bool gameOver = false;

    void reset_board(){
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                if(board[i][j] != '*'){
                    board[i][j] = ' ';
                }
            }
        }
    }

    void start_game(){
        snake.push_front(make_pair(10, 10));
        snake.push_back(make_pair(10, 9));  
        snake.push_back(make_pair(10, 8));
        //board[rand() % HEIGHT][rand() % WIDTH] = '*'; use for two fruits at a time
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

    void play_game(){
        switch (dir){
            case KB_UP:
                int new_first;
                if(snake.front().first == 0){
                    new_first = HEIGHT - 1;
                }else{
                    new_first = snake.front().first - 1;
                }

                snake.push_front(make_pair(new_first, snake.front().second));
                break;

            case KB_DOWN:
                snake.push_front(make_pair((snake.front().first + 1) % HEIGHT, snake.front().second));
                break;

            case KB_RIGHT:
                snake.push_front(make_pair(snake.front().first, (snake.front().second) + 1 % WIDTH));
                break;

            case KB_LEFT:
                snake.push_front(make_pair(snake.front().first, (snake.front().second - 1) % WIDTH));
                break;

            default:
                break;
        }
        
        if(board[snake.front().first][snake.front().second] != '*'){
            snake.pop_back();
        }else{
            board[rand() % HEIGHT][rand() % WIDTH] = '*';
        }

        if(board[snake.front().first][snake.front().second] == '#'){
            gameOver = true;
        }
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

    void show_score(){
        cout << "Game Over!" << endl << "score: " << snake.size() - 3 <<endl;
    }
};

int main(){
    game g;
    srand(time(0));
    g.reset_board();
    g.start_game();
    while(!g.gameOver){
        g.take_input();
        g.print_board();
        g.play_game();
        g.reset_board();
        if(!g.gameOver){
            system("cls");
        }
    }
    g.show_score();
}
