#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	playerName = "Player";
	playerHealth = 20;
	playerDamage = 3;
	playerArmor = 5;
}

Player::Player(string name, int health, int armor, int damage) {
	playerName = name;
	playerHealth = health;
	playerArmor = armor;
	playerDamage = damage;
}

void Player::setPlayerName(string name) {
	playerName = name;
}

string Player::getPlayerName() {
	return playerName;
}

int Player::getPlayerHealth() {
    return playerHealth;
}

void Player::setPlayerHealth(int health) {
    if (health < 0) {
        playerHealth = 0;
    }
    else {
        playerHealth = health;
    }
}

int Player::getPlayerArmor() {
    return playerArmor;
}

void Player::setPlayerArmor(int armor) {
    if (armor >= 0) {
        playerArmor = armor;
    }
}

int Player::getPlayerDamage() {
    return playerDamage;
}

void Player::setPlayerDamage(int damage) {
    if (damage >= 0) {
        playerDamage = damage;
    }
}
