#include "Player.h"
#include <iostream>

void Player::moveDown() {
	playerY++;
}
void Player::moveUp() {
	playerY--;
}
void Player::moveRight() {
	playerX++;
}
void Player::moveLeft() {
	playerX--;
}
