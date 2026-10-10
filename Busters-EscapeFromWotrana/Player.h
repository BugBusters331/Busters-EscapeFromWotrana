#pragma once
#include <iostream>
class Player
{
private:
	int playerX;
	int playerY;
	int playerHealth;
public:
	void moveDown();
	void moveUp();
	void moveRight();
	void moveLeft();
};

