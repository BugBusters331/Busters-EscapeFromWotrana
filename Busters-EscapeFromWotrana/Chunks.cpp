#include "Chunks.h"
#include <iostream>

using namespace std;

Chunks::Chunks() {
    chunkX =0;
    chunkY =0;

    board = {
        "####################",
        "#..................#",
        "#..................#",
        "#..................#",
        "#..................#",
        "#..................#",
        "#..................#",
        "#..................#",
        "#########..#########"
    };

}

void Chunks::drawChunks(int playerX, int playerY) const{
    for(int x = 0; x <board[playerY].size(); ++x){
        if (x == playerX && playerY == playerY){
            cout << "@";
        } 
        else {
            cout << board[playerY][x];
        }
    }
        cout << endl;
}

bool Chunks::isWalkable(int playerX, int playerY) const{
    if(playerY <0 || playerY >= board.size()){
        return false;
    }
    if(playerX <0 || playerX >= board[playerY].size()){
        return false;
    }
    if(board[playerY][playerX] == '#'){
        return false;
    }
    return true;
}

bool Chunks::isExit(int playerX, int playerY) const{
    if(playerY <0 || playerY >= board.size()){
        return false;
    }
    if(playerX <0 || playerX >= board[playerY].size()){
        return false;
    }
    if(board[playerY][playerX] == 'E'){
        return true;
    }
    return false;
}

int Chunks::getChunkX() const{
    return chunkX;
}

int Chunks::getChunkY() const{
    return chunkY;
}