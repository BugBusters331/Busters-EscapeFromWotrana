#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
	string playerName;
	int playerX;
	int playerY;
	int playerHealth;
public:
	Player();
	//Player(string name, int x, int y, int health);
	void setPlayerName(string name);
	string getPlayerName();

	int getPlayerX();
	int getPlayerY();

	void setPlayerX(int x);
	void setPlayerY(int y);
	void setPlayerPosition(int x, int y);
	// movement functions
	void moveDown();
	void moveUp();
	void moveRight();
	void moveLeft();

	// getters and setters for player position
	void takeDamage(int damage);
	void death();
};

