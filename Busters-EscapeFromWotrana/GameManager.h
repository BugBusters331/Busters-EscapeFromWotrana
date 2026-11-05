#pragma once
#include "Player.h"
#include "Chunks.h"
#include "LocationManager.h"


class GameManager{
private:
	Player player;
	LocationManager locationManager;
	Chunks currentChunk;

	bool isRunning;

public:
	GameManager();
	void startGame();
	void updateGame();
	void drawGame();

	void attemptMove(int newX, int newY);
	void changeChunk();
	void stopGame();
	
// locations Manager Implentation
	void initializeLocations();
	void moveForward();
	void moveBackward();
	void displayCurrentLocation();

};

