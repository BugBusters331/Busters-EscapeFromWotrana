
#include "BattleManager.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <limits>

using namespace std;


// =====================================
// CONSOLE DISPLAY HELPERS
// =====================================

void clearBattleScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForPlayer() {
    cout << "\nPress ENTER to continue...";
    cin.get();
}


// =====================================
// BATTLE MANAGER
// =====================================

BattleManager::BattleManager() {
    player = nullptr;
    enemy = nullptr;
    battleActive = false;
}


// =====================================
// START BATTLE
// =====================================

void BattleManager::startBattle(Player& player, Enemy& enemy) {
    this->player = &player;
    this->enemy = &enemy;

    battleActive = true;

    runBattle();
}


// =====================================
// BATTLE STATUS
// =====================================

bool BattleManager::isBattleActive() {
    return battleActive;
}


// =====================================
// D20 DICE ROLL
// =====================================

int BattleManager::rollD20() {
    static random_device rd;
    static mt19937 generator(rd());

    uniform_int_distribution<int> dice(1, 20);

    return dice(generator);
}


// =====================================
// PLAYER ATTACK
// =====================================

int BattleManager::playerAttack() {
    if (!battleActive || player == nullptr || enemy == nullptr) {
        return 0;
    }

    int roll = rollD20();
    int enemyAC = enemy->getEnemyArmor();
    int damage = 0;

    cout << "\n========== YOUR ATTACK ==========\n";
    cout << "D20 Roll: " << roll << endl;

    // Natural 1 always misses
    if (roll == 1) {
        cout << "Critical failure! You missed!\n";
        cout << "Damage Dealt: 0 HP\n";
        return 0;
    }

    // Check if attack hits
    if (roll >= enemyAC || roll == 20) {
        damage = player->getPlayerDamage();

        // Critical hit
        if (roll == 20) {
            damage *= 2;
            cout << "CRITICAL HIT!\n";
        }

        enemy->enemyTakeDamage(damage);

        cout << "You attacked "
            << enemy->getEnemyName() << "!\n";

        cout << "Damage Dealt: "
            << damage << " HP\n";

        // Check if enemy was defeated
        if (enemy->getEnemyHealth() <= 0) {
            cout << "\n"
                << enemy->getEnemyName()
                << " has been defeated!\n";

            battleActive = false;
        }
    }
    else {
        cout << "Your attack missed!\n";
        cout << "Damage Dealt: 0 HP\n";
    }

    return damage;
}


// =====================================
// ENEMY ATTACK
// =====================================

int BattleManager::enemyAttack() {
    if (!battleActive || player == nullptr || enemy == nullptr) {
        return 0;
    }

    int roll = rollD20();
    int playerAC = player->getPlayerArmor();
    int damage = 0;

    cout << "\n========== ENEMY ATTACK ==========\n";

    cout << enemy->getEnemyName()
        << " attacks you!\n";

    cout << "Enemy D20 Roll: "
        << roll << endl;

    // Natural 1 always misses
    if (roll == 1) {
        cout << "The enemy missed!\n";
        cout << "Damage Received: 0 HP\n";
        return 0;
    }

    // Check if enemy attack hits
    if (roll >= playerAC || roll == 20) {
        damage = enemy->getEnemyDamage();

        // Critical hit
        if (roll == 20) {
            damage *= 2;
            cout << "ENEMY CRITICAL HIT!\n";
        }

        // Apply damage to player
        int newHealth = player->getPlayerHealth() - damage;

        if (newHealth < 0) {
            newHealth = 0;
        }

        player->setPlayerHealth(newHealth);

        cout << "You were hit!\n";

        cout << "Damage Received: "
            << damage << " HP\n";

        // Check if player was defeated
        if (player->getPlayerHealth() <= 0) {
            cout << "\nYou have been defeated!\n";
            battleActive = false;
        }
    }
    else {
        cout << "You avoided the attack!\n";
        cout << "Damage Received: 0 HP\n";
    }

    return damage;
}


// =====================================
// MAIN BATTLE LOOP
// =====================================

void BattleManager::runBattle() {
    if (!battleActive || player == nullptr || enemy == nullptr) {
        return;
    }

    int round = 1;

    while (battleActive) {

        // Clear previous round
        clearBattleScreen();

        // Battle header
        cout << "====================================\n";
        cout << "          BATTLE - ROUND "
            << round << endl;
        cout << "====================================\n";

        // Current health
        cout << "\nPLAYER HP: "
            << player->getPlayerHealth() << endl;

        cout << enemy->getEnemyName()
            << " HP: "
            << enemy->getEnemyHealth() << endl;

        // Action menu
        cout << "\n----------- ACTIONS -----------\n";
        cout << "1. Attack\n";
        cout << "2. Defend (Coming Soon)\n";
        cout << "3. Item (Unavailable)\n";
        cout << "4. Flee (Unavailable)\n";

        int choice;

        cout << "\nChoose an action: ";

        // Handle invalid input
        if (!(cin >> choice)) {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "\nInvalid input!\n";
            waitForPlayer();
            continue;
        }

        // Clear remaining input
        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        // Player action
        if (choice == 1) {
            playerAttack();
        }
        else if (choice >= 2 && choice <= 4) {
            cout << "\nThis action is not available yet!\n";
            waitForPlayer();
            continue;
        }
        else {
            cout << "\nInvalid choice!\n";
            waitForPlayer();
            continue;
        }

        // Enemy turn
        if (battleActive) {
            enemyAttack();
        }

        // Round summary
        cout << "\n========== ROUND SUMMARY ==========\n";

        cout << "Your HP: "
            << player->getPlayerHealth() << endl;

        cout << enemy->getEnemyName()
            << " HP: "
            << enemy->getEnemyHealth() << endl;

        cout << "===================================\n";

        // Wait before next round
        waitForPlayer();

        round++;
    }

    // Battle finished
    clearBattleScreen();

    cout << "\n========== BATTLE ENDED ==========\n";

    if (player->getPlayerHealth() <= 0) {
        cout << "You lost the battle!\n";
    }
    else {
        cout << "You won the battle!\n";
    }

    cout << "\nYour HP: "
        << player->getPlayerHealth() << endl;

    cout << enemy->getEnemyName()
        << " HP: "
        << enemy->getEnemyHealth() << endl;

    waitForPlayer();
}


// =====================================
// ENEMY CLASS IMPLEMENTATION
// =====================================

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


// =====================================
// ENEMY NAME
// =====================================

void Enemy::setEnemyName(string name) {
    enemyName = name;
}

string Enemy::getEnemyName() {
    return enemyName;
}


// =====================================
// ENEMY HEALTH
// =====================================

void Enemy::setEnemyHealth(int health) {
    enemyHealth = health;
}

int Enemy::getEnemyHealth() {
    return enemyHealth;
}


// =====================================
// ENEMY ARMOR
// =====================================

void Enemy::setEnemyArmor(int armor) {
    enemyArmor = armor;
}

int Enemy::getEnemyArmor() {
    return enemyArmor;
}


// =====================================
// ENEMY DAMAGE
// =====================================

int Enemy::getEnemyDamage() {
    return enemyDamage;
}

void Enemy::setEnemyDamage(int damage) {
    if (damage >= 0) {
        enemyDamage = damage;
    }
}


// =====================================
// ENEMY TAKES DAMAGE
// =====================================

void Enemy::enemyTakeDamage(int damage) {
    if (damage <= 0) {
        return;
    }

    enemyHealth -= damage;

    if (enemyHealth < 0) {
        enemyHealth = 0;
    }
}
