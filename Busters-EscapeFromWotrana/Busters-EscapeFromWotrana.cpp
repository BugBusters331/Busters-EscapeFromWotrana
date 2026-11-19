
#include <iostream>
#include "Player.h"
#include "BattleManager.h"
#include "StoryManager.h"
#include "GameManager.h"
#include "PlayerInput.h"

using namespace std;

int main() {
    GameManager game;

    try {
        game.startGame();
    }
    catch (const PlayerInput::EndOfInput&) {
        return 0;
    }

    return 0;
}
