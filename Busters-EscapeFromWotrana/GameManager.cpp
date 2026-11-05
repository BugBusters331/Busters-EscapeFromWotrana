
#include "GameManager.h"
#include "Player.h"
#include "Chunks.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
GameManager::GameManager() {
    isRunning = true;
}

// Start the game
void GameManager::startGame() {
    cout << "\n===== ESCAPE FROM WOTRANA =====\n";

    // Display starting location
    locationManager.displayCurrentLocation(true);

    // Start game loop
    while (isRunning) {
        updateGame();
    }
}

// Handle player input
void GameManager::updateGame() {
    string command;

    cout << "\nWhat will you do? ";
    getline(cin, command);

    if (!cin) {
        stopGame();
        return;
    }

    if (command == "forward") {
        locationManager.moveForward();
        locationManager.displayCurrentLocation(true);
    }
    else if (command == "back") {
        locationManager.moveBackward();
        locationManager.displayCurrentLocation(false);
    }
    else if (command == "look") {
        locationManager.displayCurrentLocation(true);
    }
    else if (command == "quit") {
        stopGame();
    }
    else {
        cout << "Invalid command. Try forward, back, look, or quit.\n";
    }
}

// Stop the game
void GameManager::stopGame() {
    isRunning = false;
}
