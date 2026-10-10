#include "Player.h"
#include <iostream>
using namespace std;

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
int Player::takeDamage(int damage) { //subtracts damage from players health then outputs remaining health
	playerHealth -= damage;
	cout << playerHealth;
	if (playerHealth <= 0) {
		death();
	}
}
void Player::death() { //displays death message
	cout << "You Died. Press enter to return to main menu.";
}
