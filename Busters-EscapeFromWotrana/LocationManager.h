#pragma once

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class LocationManager{
private:
    int currentLocationIndex;
    string nameOfLocation;
    string locationDescription;
    string briefLocationDescription;
public:
    LocationManager(int index, const string& name, const string& description, const string& briefDescription)
        : currentLocationIndex(index), nameOfLocation(name), locationDescription(description), briefLocationDescription(briefDescription) {}
  
    int getCurrentLocationIndex() const { return currentLocationIndex; }
    string getNameOfLocation() const { return nameOfLocation; }
    string getLocationDescription() const { return locationDescription; }
    string getBriefLocationDescription() const { return briefLocationDescription; }

    void setCurrentLocationIndex(int index) { currentLocationIndex = index; }
    void setNameOfLocation(const string& name) { nameOfLocation = name; }
    void setLocationDescription(const string& description) { locationDescription = description; }
    void setBriefLocationDescription(const string& briefDescription) { briefLocationDescription = briefDescription; }
};

