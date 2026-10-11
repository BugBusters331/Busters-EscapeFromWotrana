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
    string firstMessage = "Welcome to the game";
    first.printSlow(firstMessage);
    return 0;   
}