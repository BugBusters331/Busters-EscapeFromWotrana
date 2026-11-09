
#pragma once

#include <string>
#include <thread>
#include <chrono>
#include "Player.h"
#include "Enemy.h"
#include "BattleManager.h"

using namespace std;

// Handles dialogue and text output
class dialogue {
public:
    int speedChoice();
    void print(string text);
    void printSlow(string text, int speed);
    void pause(int pauseTime, int speed);
    void dots(int dots, int speed);
    string prompt(string text);
    string pars(string text);
};

// Handles story progression
class StoryManager {
private:
    Player& player;
    Enemy lyre;
    BattleManager battle;
    dialogue first;

    int speed = 0;
    string stdPrompt = "What will you do?";
    bool choicePicked = false;
    string choice1;

public:
    StoryManager(Player& player);

    void startStory();
    void openingScene();
    void firstCrash();
};
