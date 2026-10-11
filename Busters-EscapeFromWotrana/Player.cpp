#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	playerX = 1;
	playerY = 1;
	playerHealth = 100;
}

void Player::setPlayerName(string name) {
	playerName = name;
}

string Player::getPlayerName() {
	return playerName;
}

void Player::moveDown() { //moves players y coordinate down 1
	playerY++;
}
void Player::moveUp() { //moves players y coordinate up 1
	playerY--;
}
void Player::moveRight() { //moves players x coordinate right 1
	playerX++;
}
void Player::moveLeft() { //moves players x coordinate left 1
	playerX--;
}

void Player::takeDamage(int damage) { //subtracts damage from players health then outputs remaining health
	playerHealth -= damage;
	cout << playerHealth;
	if (playerHealth <= 0) {
		death();
	}
	return playerHealth;
}
void Player::death() { //displays death message
	cout << "You Died. Press enter to return to main menu.";
}

int Player::getPlayerX() { //returns players x coordinate
	return playerX;
}

int Player::getPlayerY() { //returns players y coordinate
	return playerY;
}

void Player::setPlayerX(int x) { //sets players x coordinate
	playerX = x;
	
}

void Player::setPlayerY(int y) { //sets players y coordinate
	playerY = y;
	
}

void Player::setPlayerPosition(int x, int y) { //sets players x and y coordinates
	playerX = x;
	playerY = y;
}