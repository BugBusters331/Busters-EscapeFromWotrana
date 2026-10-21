#include "BattleManager.h"
#include <iostream>

using namespace std;

BattleManager::BattleManager(){
    player = nullptr;
    enemy = nullptr;
    isBattleActive = false;
}

void BattleManager::startBattle(Player& player, Enemy& enemy){
    this->player = &player;
    this->enemy = &enemy;
    isBattleActive = true;

    cout << "\n===== BATTLE STARTED =====\n";
    cout << "Enemy: " << enemy.getEnemyName() << endl;
    cout << "Player Health: " << player.getPlayerHealth() << endl;
    cout << "Enemy Health: " << enemy.getEnemyHealth() << endl;
    cout << "==========================\n";
}

bool BattleManager::isBattleActive(){
    return isBattleActive;
}