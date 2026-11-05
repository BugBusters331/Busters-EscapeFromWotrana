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
  
    int getCurrentLocationIndex();
    string getNameOfLocation();
    string getLocationDescription();
    string getBriefLocationDescription();

    void setCurrentLocationIndex(int index);
    void setNameOfLocation(const string& name);
    void setLocationDescription(const string& description);
    void setBriefLocationDescription(const string& briefDescription);
};

