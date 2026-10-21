#pragma once

#include "Player.h"
//#include "Enemy.h"

class BattleManager{
    private:
        Player* player;
        Enemy* enemy;
    public:
        BattleManager();

        void startBattle(Player& player, Enemy& enemy);

        bool isBattleActive();
};

class Enemy{
    private:
        string enemyName;
        int enemyHealth;
    public:
        Enemy();
        Enemy(string name, int health);
        void setEnemyName(string name);
        string getEnemyName();
        void setEnemyHealth(int health);
        int getEnemyHealth();
};