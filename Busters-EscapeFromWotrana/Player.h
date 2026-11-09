#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
	string playerName;

	int playerHealth;
	int playerDamage;
	int playerArmor;
public:
	Player();
	Player(string name, int health, int armor, int damage);
	void setPlayerName(string name);
	string getPlayerName();



	// getters and setters for player stats
	int getPlayerDamage();
	void setPlayerDamage(int damage);
	int getPlayerArmor();
	void setPlayerArmor(int armor);
	
	
	// getters and setters for player health
	int getPlayerHealth();
	void setPlayerHealth(int health);
};

