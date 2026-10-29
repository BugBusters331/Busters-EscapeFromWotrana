#include "GameManager.h"
#include "StoryManager.h"
#include "BattleManager.h"
#include "MainMenu.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;


int main() {

    // TEMPORARY BATTLE TEST
    Player player;
    player.setPlayerName("Captain");
    player.setPlayerHealth(100);

    Enemy lyre("Lyre", 100, 12, 10);

    BattleManager battle;
    battle.startBattle(player, lyre);

    while (battle.isBattleActive()) {
        cout << "\nPress Enter to attack...";
        cin.get();

        battle.playerAttack(); // Player will attack first

        if (battle.isBattleActive()) { // Enemy will attack back if its still alive
            battle.enemyAttack();
        }
    }

    cout << "\nBattle test complete!" << endl;

    return 0;

   
}


