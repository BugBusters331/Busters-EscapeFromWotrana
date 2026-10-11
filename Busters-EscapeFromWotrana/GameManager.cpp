#include "GameManager.h"
#include "Player.h"
#include "Chunks.h"
#include <iostream>
#include <conio.h>

using namespace std;

GameManager::GameManager(){
	isRunning = true;
}

void GameManager::startGame() {
	while (isRunning) {
		drawGame();
		handleInput();
		updateGame();
	}
}

void GameManager::handleInput() {
	int key = _getch();

	int newX = player.getPlayerX();
	int newY = player.getPlayerY();

	if (key == 0 || key == 224) {
		key = _getch(); // Handle arrow keys

		if (key == 72) { // Up arrow
			newY--;
		}
		else if (key == 80) { // Down arrow
			newY++;
		}
		else if (key == 75) { // Left arrow
			newX--;
		}
		else if (key == 77) { // Right arrow
			newX++;
		}
	}

	attemptMove(newX, newY);
}

void GameManager::attemptMove(int newX, int newY) {
	if (currentChunk.isWalkable(newX, newY)) {
		player.setPlayerPosition(newX, newY);
	}
}

void GameManager::updateGame(){
	if (currentChunk.isExit(player.getPlayerX(), player.getPlayerY()))
	{
		changeChunk();
	}
}

void GameManager::drawGame() {
	system("cls"); // Clear the console
	currentChunk.drawChunks(player.getPlayerX(), player.getPlayerY());
}

void GameManager::changeChunk() {
	// add chunk switching later
}

void GameManager::stopGame() {
	isRunning = false;
}