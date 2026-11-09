
#include "LocationManager.h"
#include <cctype>

using namespace std;

// Constructor
LocationManager::LocationManager() {
    currentLocationIndex = 0;
    initializeLocations();
}

// Initialize all locations
void LocationManager::initializeLocations() {
    locations.clear();

    // 0 - Ship
    locations.push_back({
        "Ship",
        "You enter your damaged spaceship.",
        "You return to your ship.",
        "", "", false,
        {1}
    });

    // 1 - Crash Site
    locations.push_back({
        "Crash Site",
        "You are standing next to your broken spaceship.",
        "You are back at the Crash Site.",
        "", "", false,
        {0, 2}
    });

    // 2 - Forest
    locations.push_back({
        "Forest",
        "You enter a dense forest filled with trees.",
        "You are back in the Forest.",
        "", "", false,
        {1, 3, 4, 6}
    });

    // 3 - City Entrance
    locations.push_back({
        "City Entrance",
        "You arrive at the entrance of a city.",
        "You return to the City Entrance.",
        "", "", false,
        {2}
    });

    // 4 - Plains
    locations.push_back({
        "Plains",
        "You enter a wide open field.",
        "You return to the Plains.",
        "", "", false,
        {2, 5}
    });

    // 5 - Desert
    locations.push_back({
        "Desert",
        "You enter a hot, dry desert.",
        "You return to the Desert.",
        "", "", false,
        {4}
    });

    // 6 - River
    locations.push_back({
        "River",
        "You arrive at a flowing river.",
        "You return to the River.",
        "", "", false,
        {2, 7, 8}
    });

    // 7 - Lake
    locations.push_back({
        "Lake",
        "You arrive at a quiet lake.",
        "You return to the Lake.",
        "", "", false,
        {6}
    });

    // 8 - Mountain
    locations.push_back({
        "Mountain",
        "You approach a tall mountain.",
        "You return to the Mountain.",
        "", "", false,
        {6}
    });

    // Start at Crash Site
    currentLocationIndex = 1;
}

// Display connected locations
void LocationManager::displayAvailableLocations() {
    cout << "\nAvailable Locations:\n";

    for (int index : locations[currentLocationIndex].connectedLocations) {
        cout << "- " << locations[index].nameOfLocation << endl;
    }
}

// Move to a location by name
void LocationManager::goToLocation(const string& locationName) {
    int newIndex = -1;

    // Convert input to lowercase
    string targetName = locationName;

    for (char& c : targetName) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }

    // Search for matching location
    for (int i = 0; i < static_cast<int>(locations.size()); i++) {
        string name = locations[i].nameOfLocation;

        for (char& c : name) {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }

        if (name == targetName) {
            newIndex = i;
            break;
        }
    }

    if (newIndex == -1) {
        cout << "Location not found.\n";
        return;
    }

    // Check connected locations
    bool canTravel = false;

    for (int index : locations[currentLocationIndex].connectedLocations) {
        if (index == newIndex) {
            canTravel = true;
            break;
        }
    }

    if (!canTravel) {
        cout << "You cannot travel to that location from here.\n";
        return;
    }

    // Move to new location
    currentLocationIndex = newIndex;

    // Show full description on first visit,
    // brief description when returning
    bool firstVisit = !locations[currentLocationIndex].hasVisited;

    displayCurrentLocation(firstVisit);

    locations[currentLocationIndex].hasVisited = true;

    displayAvailableLocations();
}

// Display location information
void LocationManager::displayCurrentLocation(bool fullDescription) {
    if (locations.empty()) {
        cout << "No locations available.\n";
        return;
    }

    cout << "\nLocation: " << getNameOfLocation() << endl;

    if (fullDescription) {
        cout << getLocationDescription() << endl;
    }
    else {
        cout << getBriefLocationDescription() << endl;
    }
}

// Getters
int LocationManager::getCurrentLocationIndex() {
    return currentLocationIndex;
}

string LocationManager::getNameOfLocation() {
    return locations[currentLocationIndex].nameOfLocation;
}

string LocationManager::getLocationDescription() {
    return locations[currentLocationIndex].locationDescription;
}

string LocationManager::getBriefLocationDescription() {
    return locations[currentLocationIndex].briefLocationDescription;
}

// Setters
void LocationManager::setCurrentLocationIndex(int index) {
    if (index >= 0 && index < static_cast<int>(locations.size())) {
        currentLocationIndex = index;
    }
}

void LocationManager::setNameOfLocation(const string& name) {
    locations[currentLocationIndex].nameOfLocation = name;
}

void LocationManager::setLocationDescription(const string& description) {
    locations[currentLocationIndex].locationDescription = description;
}

void LocationManager::setBriefLocationDescription(const string& briefDescription) {
    locations[currentLocationIndex].briefLocationDescription = briefDescription;
}
