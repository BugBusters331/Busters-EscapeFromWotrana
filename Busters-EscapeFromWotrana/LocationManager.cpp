
#include "LocationManager.h"
#include <cctype>

using namespace std;

// Constructor
LocationManager::LocationManager() {
    currentLocationIndex = 0;
    initializeLocations();
}

// Add all locations
void LocationManager::initializeLocations() {
    locations.clear();

    locations.push_back({
        "Crash Site",
        "You are standing next to your broken spaceship.",
        "You are back at the Crash Site."
    });

    locations.push_back({
        "Forest",
        "You enter a forest filled with trees.",
        "You are back in the Forest."
    });

    locations.push_back({
        "City Entrance",
        "You arrive at the entrance of a city.",
        "You are back at the City Entrance."
    });

    currentLocationIndex = 0;
}

// Display available locations
void LocationManager::displayAvailableLocations() {
    cout << "\nAvailable Locations:\n";

    if (currentLocationIndex > 0) {
        cout << "- " << locations[currentLocationIndex - 1].nameOfLocation << endl;
    }

    if (currentLocationIndex + 1 < static_cast<int>(locations.size())) {
        cout << "- " << locations[currentLocationIndex + 1].nameOfLocation << endl;
    }
}

// Move to a connected location by name
void LocationManager::goToLocation(const string& locationName) {
    int newIndex = -1;

    // Convert player input to lowercase
    string targetName = locationName;

    for (char& c : targetName) {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }

    // Search for the location
    for (int i = 0; i < static_cast<int>(locations.size()); i++) {
        string name = locations[i].nameOfLocation;

        // Convert stored location name to lowercase
        for (char& c : name) {
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        }

        if (name == targetName) {
            newIndex = i;
            break;
        }
    }

    // Location does not exist
    if (newIndex == -1) {
        cout << "Location not found.\n";
        return;
    }

    // Check if location is connected
    if (newIndex == currentLocationIndex - 1 ||
        newIndex == currentLocationIndex + 1) {

        currentLocationIndex = newIndex;

        displayCurrentLocation(true);
        displayAvailableLocations();
    }
    else {
        cout << "You cannot travel to that location from here.\n";
    }
}

// Display current location
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