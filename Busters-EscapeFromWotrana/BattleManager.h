#pragma once

#include "Player.h"
#include "random"
//#include "Enemy.h"

class Enemy {
private:
    string enemyName;
    int enemyHealth;
    int enemyArmor;
    int enemyDamage;

public:
    Enemy();
    Enemy(string name, int health, int armor);

    void setEnemyName(string name);
    string getEnemyName();

    void setEnemyHealth(int health);
    int getEnemyHealth();

    void setEnemyArmor(int armor);
    int getEnemyArmor();

    void enemyTakeDamage(int damage);

    int getEnemyDamage();
    void setEnemyDamage(int damage);
};

class BattleManager {
private:
    Player* player;
    Enemy* enemy;
    bool battleActive;
public:
    BattleManager();

    void startBattle(Player& player, Enemy& enemy);

    bool isBattleActive();

    int rollD20();
    int playerAttack();

    int enemyAttack();
};