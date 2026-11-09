
#include "GameManager.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Constructor
GameManager::GameManager() {
    isRunning = true;
}

// Start the game
void GameManager::startGame() {

    // Show starting location
    locationManager.displayCurrentLocation(true);

    // Show available locations
    locationManager.displayAvailableLocations();

    // Start game loop
    while (isRunning) {
        updateGame();
    }
}

// Update game and handle player commands
void GameManager::updateGame() {
    string command;

    cout << "\nWhat will you do? ";
    getline(cin, command);

    if (!cin) {
        stopGame();
        return;
    }

    // Convert command to lowercase
    for (char& c : command) {
        c = static_cast<char>(
            tolower(static_cast<unsigned char>(c))
        );
    }

    // Move to a location
    if (command.substr(0, 5) == "goto ") {
        string locationName = command.substr(5);

        locationManager.goToLocation(locationName);
    }

    // Look around current location
    else if (command == "look") {
        locationManager.displayCurrentLocation(true);
    }

    // Show available locations
    else if (command == "locations") {
        locationManager.displayAvailableLocations();
    }

    // Quit game
    else if (command == "quit") {
        stopGame();
    }

    // Invalid command
    else {
        cout << "Invalid command.\n";
        cout << "Commands: goto [location], look, locations, quit\n";
    }
}

// Stop the game
void GameManager::stopGame() {
    isRunning = false;
}
