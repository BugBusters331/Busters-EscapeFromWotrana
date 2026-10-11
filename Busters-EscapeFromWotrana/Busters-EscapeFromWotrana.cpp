#include "GameManager.h"
#include "StoryManager.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

int main(){
    cout << "Game In Progress" << endl;
    dialogue first;
    string line1 = "It's been a long day of traveling through space, hasn't it?";
    string line2 = "Your ship's practically out of fuel, gonna have to take care of that soon.";
    string line3 = "And these missions aren't getting any easier either.";
    string line4 = "Being the reasonably tired space captain you are, you sit back in your cockpit chair and gaze at the scenery outside the ship.";
    first.printSlow(line1);
    first.printSlow(line2);
    first.printSlow(line3);
    first.printSlow(line4);
    return 0;   
}