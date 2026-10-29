#pragma once
#include "Player.h"
#include "Chunks.h"


class GameManager{
private:
	Player player;
	Chunks currentChunk;

	bool isRunning;

public:
	GameManager();
	void startGame();
	void handleInput();
	void updateGame();
	void drawGame();

	void attemptMove(int newX, int newY);
	void changeChunk();
	void stopGame();

};

