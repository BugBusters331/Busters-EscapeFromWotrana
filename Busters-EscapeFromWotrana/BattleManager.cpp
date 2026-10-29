
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

	runBattle();
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
        // Get damage from player stats
        damage = player->getPlayerDamage();

        // Check for critical hit
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
        // Get damage from enemy stats
        damage = enemy->getEnemyDamage();

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


void BattleManager::runBattle() {
    if (!battleActive || player == nullptr || enemy == nullptr) {
        return;
    }

    while (battleActive) {
        int choice;

        cout << "\n===== PLAYER TURN =====\n";
        cout << "Player HP: " << player->getPlayerHealth() << endl;
        cout << enemy->getEnemyName() << " HP: "
             << enemy->getEnemyHealth() << endl;

        cout << "\n1. Attack\n";
        cout << "2. Defend (Coming Soon)\n";
        cout << "3. Item (Unavailable)\n";
        cout << "4. Flee (Unavailable)\n";
        cout << "Choose an action: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input!\n";
            continue;
        }

        if (choice == 1) {
            playerAttack();
        }
        else if (choice >= 2 && choice <= 4) {
            cout << "This action is not available yet!\n";
            continue;
        }
        else {
            cout << "Invalid choice!\n";
            continue;
        }

        // Stop if enemy was defeated
        if (!battleActive) {
            break;
        }

        cout << "\n===== ENEMY TURN =====\n";
        enemyAttack();
    }

    cout << "\n===== BATTLE ENDED =====\n";
}


// Enemy class implementation


Enemy::Enemy() {
    enemyName = "Unknown";
    enemyHealth = 100;
    enemyArmor = 10;
    enemyDamage = 20;
}

Enemy::Enemy(string name, int health, int armor, int damage) {
    enemyName = name;
    enemyHealth = health;
    enemyArmor = armor;
    enemyDamage = damage;
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