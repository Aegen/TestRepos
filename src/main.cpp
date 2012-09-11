#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

vector< vector<int> > board(8);

int bannedX[8] = {9,9,9,9,9,9,9,9};
int bannedY[8] = {9,9,9,9,9,9,9,9};

inline bool isBanned(int _x, int _y){
    for(int a = 0; a < 8; a++){
        if( _x == bannedX[a] || _y == bannedY[a])
            return true;
    }
    return false;
}

inline bool isCorrect(){
    bool correct = true;

    int x;
    int y;

    for(int a = 0; a < 7; a++){
        for(int b = a + 1; b < 8; b++){
            x = abs(bannedX[a] - bannedX[b]);
            y = abs(bannedY[a] - bannedY[b]);

            if(x == y){
                correct = false;
            }

        }
    }

    return correct;
}

 inline void resetBoard(){
    for (int a = 0; a < 8; a++)
        for(int b = 0; b < 8; b++)
            board.at(a).at(b) = 0;
}

inline void addToBanned(int _x, int _y){
    for(int a =0; a < 8; a++){
        if(bannedX[a] == 9){
            bannedX[a] = _x;
            bannedY[a] = _y;
            a = 8;
        }
    }
}

inline void resetBanned(){
    for(int a = 0; a < 8; a++){
        bannedX[a] = 9;
        bannedY[a] = 9;
    }
}

inline void initializeBoard(){
    for(int a = 0; a < 8; a++)
        board.at(a).resize(8);
    resetBoard();
}

inline void printBoard(){
    for(int a = 0; a < 8; a++){
        for(int b = 0; b < 8; b++)
            cout << board.at(a).at(b) << " ";
        cout << endl;
    }
}

int main()
{
    initializeBoard();

    time_t now;
    time(&now);
    srand((unsigned int)now);

    int x;
    int y;

    bool done = false;

    while(done == false){

        resetBoard();
        resetBanned();

        for(int d = 0; d < 8;){

            x = rand() % 8;
            y = rand() % 8;

            if(!isBanned(x,y)){

                board[x][y] = 1;
                addToBanned(x,y);
                d++;

            }
        }

        done = isCorrect();
    }

    printBoard();

    return 0;
}
