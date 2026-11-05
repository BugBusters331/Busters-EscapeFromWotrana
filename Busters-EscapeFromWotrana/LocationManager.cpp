#include "LocationManager.h"

LocationManager::LocationManager(int index, const string& name, const string& description, const string& briefDescription)
    : currentLocationIndex(index), nameOfLocation(name), locationDescription(description), briefLocationDescription(briefDescription) {}


// Setters
int LocationManager::getCurrentLocationIndex() {
    return currentLocationIndex;
}

string LocationManager::getNameOfLocation() {
    return nameOfLocation;
}

string LocationManager::getLocationDescription() {
    return locationDescription;
}

string LocationManager::getBriefLocationDescription() {
    return briefLocationDescription;
}

// Getters
void LocationManager::setCurrentLocationIndex(int index) {
    currentLocationIndex = index;
}

void LocationManager::setNameOfLocation(const string& name) {
    nameOfLocation = name;
}

void LocationManager::setBriefLocationDescription(const string& briefDescription) {
    briefLocationDescription = briefDescription;
}

void LocationManager::setLocationDescription(const string& description) {
    locationDescription = description;
}