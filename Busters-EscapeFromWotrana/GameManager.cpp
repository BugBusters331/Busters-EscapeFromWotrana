
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

    // Show starting location
    locationManager.displayCurrentLocation(true);

    // Show where the player can go
    locationManager.displayAvailableLocations();

    // Start game loop
    while (isRunning) {
        updateGame();
    }
}
//updates game status
void GameManager::updateGame() {
    string command;

    cout << "\nWhat will you do? ";
    getline(cin, command);

    if (!cin) {
        stopGame();
        return;
    }

    if (command.substr(0, 5) == "goto ") {
        string locationName = command.substr(5);

        locationManager.goToLocation(locationName);
    }
    else if (command == "look") {
        locationManager.displayCurrentLocation(true);
    }
    else if (command == "locations") {
        locationManager.displayAvailableLocations();
    }
    else if (command == "quit") {
        stopGame();
    }
    else {
        cout << "Invalid command.\n";
    }
}

// Stop the game
void GameManager::stopGame() {
    isRunning = false;
}
