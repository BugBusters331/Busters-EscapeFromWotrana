#include "GameManager.h"
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

GameManager::GameManager() : storyManager(player), isRunning(true) {}

void GameManager::startGame() {
    bool gameStarted = false;
    while (isRunning && !gameStarted) {
        menu.displayMenu();
        int choice = menu.getuserChoice();
        if (!cin) {
            if (cin.eof()) { stopGame(); return; }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Enter 1, 2, or 3.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (choice == 1) {
            gameStarted = true;
        } else if (choice == 2) {
            menu.displayUserManual();
            string input;
            getline(cin, input); // Enter returns to menu
            if (!cin) { stopGame(); return; }
        } else if (choice == 3) {
            stopGame();
            return;
        } else {
            cout << "Invalid choice. Enter 1, 2, or 3.\n";
        }
    }
    if (!gameStarted) return;

    storyManager.startStory();
    locationManager.displayCurrentLocation(true);
    locationManager.displayAvailableLocations();
    while (isRunning) updateGame();
}

void GameManager::updateGame() {
    string command;
    cout << "\nWhat will you do? ";
    getline(cin, command);
    if (!cin) { stopGame(); return; }

    for (char& c : command)
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));

    if (command.rfind("goto ", 0) == 0) {
        locationManager.goToLocation(command.substr(5));
    } else if (command == "look") {
        locationManager.displayCurrentLocation(true);
    }
    else if (command == "locations") {
        locationManager.displayAvailableLocations();
    }
    else if (command == "inspect exterior") {
        if (locationManager.getNameOfLocation() == "Crash Site") {
            inspection.inspectExterior(3);
        }
        else {
            cout << "You cannot inspect the spaceship's exterior from this location." << endl;
        }
    }
    else if (command == "inspect interior"){
        if (locationManager.getNameOfLocation() == "Ship") {
            inspection.inspectShip(3);
        }
        else {
            cout << "You must be inside the ship to inspect its interior." << endl;
        }
    } else if (command == "quit") {
        stopGame();
    } else {
        cout << "Invalid command. Use goto [location], look, locations, inspect interior, inspect exterior, or quit.\n";
    }
}

void GameManager::stopGame() { isRunning = false; }

// drawGame(), attemptMove(), changeChunk() are still only declarations.

