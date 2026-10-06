#pragma once
#include <iostream>
class Player
{
private:
	int x;
	int y;
	int health;
public:
	Player();
	void startPositon()
	{
		x = 0;
		y = 0;
	};
	void moveDown()
	{
		y++;
	}
	void moveUp()
	{
		y--;
	}
	void moveRight()
	{
		x++;
	}
	void moveLeft()
	{
		x--;
	}
	void takeDamage(int damage)
	{
		Player.health -= damage;
		std::cout << health;
		if (Player.health <= 0)
		{
			death();
		}
	}
	void death()
	{
		std::cout << "You Died. Press enter to return to main menu."
	}
};

