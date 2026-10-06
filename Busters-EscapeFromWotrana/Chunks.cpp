#include "Chunks.h"
#include <iostream>

using namespace std;

// Legend for the board symbols:
// # = Wall
// . = Empty space
// E = Exit
// @ = Player

// Implementation of the Chunks class methods

Chunks::Chunks() { // Constructor initializes the chunk coordinates and the board
    chunkX =0; // Initialize the X coordinate of the current chunk
    chunkY =0; // Initialize the Y coordinate of the current chunk

    board = { // Initialize the board with the chunk layout
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
// drawChunks method displays the current chunk with the player's position marked by '@'
void Chunks::drawChunks(int playerX, int playerY) const{ 
    for(int x = 0; x <board[playerY].size(); ++x){
        if (x == playerX && playerY == playerY){
            cout << "@"; // Display the player at the current position
        } 
        else {
            cout << board[playerY][x]; // Display the board cell at the current position
        }
    }
        cout << endl; // Move to the next line after displaying the current row of the chunk
}

bool Chunks::isWalkable(int playerX, int playerY) const{ // Checks if the player can walk on the specified cell
    if(playerY <0 || playerY >= board.size()){ // Check if the player's Y coordinate is out of bounds
        return false;
    }
    if(playerX <0 || playerX >= board[playerY].size()){ // Check if the player's X coordinate is out of bounds
        return false;
    }
    if(board[playerY][playerX] == '#'){ // Check if the specified cell is a wall
        return false;
    }
    return true; // The specified cell is walkable
}

bool Chunks::isExit(int playerX, int playerY) const{ // Checks if the specified cell is an exit
    if(playerY <0 || playerY >= board.size()){ // Check if the player's Y coordinate is out of bounds
        return false;
    }
    if(playerX <0 || playerX >= board[playerY].size()){ // Check if the player's X coordinate is out of bounds
        return false;
    }
    if(board[playerY][playerX] == 'E'){ // Check if the specified cell is an exit
        return true;
    }
    return false;
}

int Chunks::getChunkX() const{ // Returns the X coordinate of the current chunk
    return chunkX;
}

int Chunks::getChunkY() const{ // Returns the Y coordinate of the current chunk
    return chunkY;
}