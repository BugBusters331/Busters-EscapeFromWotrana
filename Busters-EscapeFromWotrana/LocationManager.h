
#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Stores information for each location
struct Location {
    string nameOfLocation;
    string locationDescription;
    string briefLocationDescription;

    string npcDialogue;
    string firstVisitScene;

    bool hasVisited = false;

    // Stores indices of connected locations
    vector<int> connectedLocations;
};

class LocationManager {
private:
    vector<Location> locations;
    int currentLocationIndex;

public:
    LocationManager();

    // Initialize locations
    void initializeLocations();

    // Movement
    void displayAvailableLocations();
    void goToLocation(const string& locationName);

    // Display descriptions
    void displayCurrentLocation(bool fullDescription);

    // Getters
    int getCurrentLocationIndex();
    string getNameOfLocation();
    string getLocationDescription();
    string getBriefLocationDescription();

    // Setters
    void setCurrentLocationIndex(int index);
    void setNameOfLocation(const string& name);
    void setLocationDescription(const string& description);
    void setBriefLocationDescription(const string& briefDescription);
};
