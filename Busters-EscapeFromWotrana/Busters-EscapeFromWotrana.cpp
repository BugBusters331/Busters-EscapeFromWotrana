
#include <iostream>
#include "Player.h"
#include "BattleManager.h"

using namespace std;

int main() {

    
 

	Player player("Captain", 100, 15, 10);
    Enemy lyre("Lyre", 100, 10, 20);

    
    BattleManager battle;

    cout << "Starting Battle Manager Test...\n";

    
    battle.startBattle(player, lyre);

    cout << "\nBattle test completed!\n";

    return 0;
}


/*int main() {
    GameManager game;
    game.startGame();
    return 0;
}*/
