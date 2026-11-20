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

	//Defult is set to false
	bool defeatedNpc1 = false;
	bool defeatedNpc2 = false;
	bool defeatedNpc3 = false;
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

	//NPC WIN/LOSS PlaceHolder

	void markNpc1Defeated() { defeatedNpc1 = true; }
	void markNpc2Defeated() { defeatedNpc2 = true; }
	void markNpc3Defeated() { defeatedNpc3 = true; }
	

	bool hasDefeatedNpc1() const { return defeatedNpc1; }
	bool hasDefeatedNpc2() const { return defeatedNpc2; }
	bool hasDefeatedNpc3() const { return defeatedNpc3; }
	
	
};

