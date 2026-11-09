#pragma once
#include "Player.h"
#include "Chunks.h"
#include "LocationManager.h"
#include "StoryManager.h"
#include "MainMenu.h"

class GameManager {
private:
    Player player;
    StoryManager storyManager;
    LocationManager locationManager;
    MainMenu menu;
    Chunks currentChunk;
    bool isRunning;
public:
    GameManager();
    void startGame();
    void updateGame();
    void drawGame();
    void attemptMove(int newX, int newY);
    void changeChunk();
    void stopGame();
};
