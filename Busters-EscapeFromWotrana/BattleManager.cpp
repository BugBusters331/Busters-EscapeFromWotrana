
#include "BattleManager.h"
#include <iostream>
#include <random>

using namespace std;

BattleManager::BattleManager() {
    player = nullptr;
    enemy = nullptr;
    battleActive = false;
}

void BattleManager::startBattle(Player& player, Enemy& enemy) {
    this->player = &player;
    this->enemy = &enemy;

    battleActive = true;

    cout << "\n===== BATTLE STARTED =====\n";
    cout << "Enemy: " << enemy.getEnemyName() << endl;
    cout << "Player Health: " << player.getPlayerHealth() << endl;
    cout << "Enemy Health: " << enemy.getEnemyHealth() << endl;
    cout << "==========================\n";
}

bool BattleManager::isBattleActive() {
    return battleActive;
}

int BattleManager::rollD20() {
    static random_device rd;
    static mt19937 generator(rd());

    uniform_int_distribution<int> dice(1, 20);

    return dice(generator);
}

int BattleManager::playerAttack() {
    if (!battleActive || player == nullptr || enemy == nullptr) {
        return 0;
    }

    int roll = rollD20();
    int enemyAC = enemy->getEnemyArmor();
    int damage = 0;

    cout << "\nYou rolled a D20: " << roll << endl;

    // Natural 1 is an automatic miss
    if (roll == 1) {
        cout << "Critical failure! Your attack missed!\n";
        return 0;
    }

    // Check if the attack hits
    if (roll >= enemyAC || roll == 20) {
        static random_device rd;
        static mt19937 generator(rd());

        uniform_int_distribution<int> damageRoll(20, 40);
        damage = damageRoll(generator);

        // Natural 20 deals double damage
        if (roll == 20) {
            damage *= 2;
            cout << "Critical hit!\n";
        }

        enemy->enemyTakeDamage(damage);

        cout << "Attack hit for " << damage << " damage!\n";
        cout << "Enemy Health: "
             << enemy->getEnemyHealth() << endl;

        // Check if enemy was defeated
        if (enemy->getEnemyHealth() <= 0) {
            cout << "\nEnemy defeated!\n";
            battleActive = false;
        }
    }
    else {
        cout << "Your attack missed!\n";
    }

    return damage;
}

int BattleManager::enemyAttack() {
    if (!battleActive || player == nullptr || enemy == nullptr) {
        return 0;
    }

    int roll = rollD20();
    int playerAC = player->getPlayerArmor();
    int damage = 0;

    cout << "\nEnemy rolled a D20: " << roll << endl;

    if (roll == 1) {
        cout << "Enemy missed!\n";
        return 0;
    }

    if (roll >= playerAC || roll == 20) {
        static random_device rd;
        static mt19937 generator(rd());

        uniform_int_distribution<int> damageRoll(20, 40);
        damage = damageRoll(generator);

        if (roll == 20) {
            damage *= 2;
            cout << "Enemy critical hit!\n";
        }

        player->setPlayerHealth(
            player->getPlayerHealth() - damage
        );

        cout << "Enemy hit for " << damage << " damage!\n";
        cout << "Player Health: "
            << player->getPlayerHealth() << endl;

        if (player->getPlayerHealth() <= 0) {
            cout << "\nYou lose!\n";
            battleActive = false;
        }
    }
    else {
        cout << "Enemy attack missed!\n";
    }
    return damage;
}



// Enemy class implementation


Enemy::Enemy() {
    enemyName = "Unknown";
    enemyHealth = 100;
    enemyArmor = 10;
    enemyDamage = 3;
}

Enemy::Enemy(string name, int health, int armor) {
    enemyName = name;
    enemyHealth = health;
    enemyArmor = armor;
    enemyDamage = 3;
}

void Enemy::setEnemyName(string name) {
    enemyName = name;
}

string Enemy::getEnemyName() {
    return enemyName;
}

void Enemy::setEnemyHealth(int health) {
    enemyHealth = health;
}

int Enemy::getEnemyHealth() {
    return enemyHealth;
}

void Enemy::setEnemyArmor(int armor) {
    enemyArmor = armor;
}

int Enemy::getEnemyArmor() {
    return enemyArmor;
}

void Enemy::enemyTakeDamage(int damage) {
    if (damage <= 0) {
        return;
    }

    enemyHealth -= damage;

    if (enemyHealth < 0) {
        enemyHealth = 0;
    }
}

int Enemy::getEnemyDamage() {
    return enemyDamage;
}

void Enemy::setEnemyDamage(int damage) {
    if (damage >= 0) {
        enemyDamage = damage;
    }
}