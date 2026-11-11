#pragma once
#include <string>
#include <thread>
#include <chrono>
#include "Player.h"
#include "BattleManager.h"
using namespace std;

// Keep dialogue method implementations in your existing StoryManager.cpp.
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

    void introDialogue();
    void engineRepair();
    void lyreIntro();
    void lyreBattleEnd();
    void firstCrash();
    void climbMinigame();
    void openingScene();
public:
    explicit StoryManager(Player& player);
    void startStory();
};
