#pragma once
#include <iostream>
class Player {
private:
	string playerName;
	int playerX;
	int playerY;
	int playerHealth;
public:
	Player(string name, int x, int y, int health);
	void setPlayerName(string name);
	void moveDown();
	void moveUp();
	void moveRight();
	void moveLeft();
	int takeDamage(int damage);
	void death();
};

