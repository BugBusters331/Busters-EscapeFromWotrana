#include "StoryManager.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>


using namespace std;

int dialogue::speedChoice() {
    string sampleLine = "Text can appear slowly (like it's doing now) to add to the experience.";
    printSlow(sampleLine, 1);
    string ask = "Press 1 for slow text, press 2 for fast text, press 3 for instant text";
    bool speedChosen = false;
    while (!speedChosen) {
        string speed = prompt(ask);
        if (speed == "1") {
            return 1;
        }
        else if (speed == "2") {
            return 2;
        }
        else if (speed == "3") {
            return 1000;
        }
        else {
            cout << "Invalid input. ";
        }
    }

}

void dialogue::print( string text) {
    cout << text;
    cout << endl;
}

void dialogue::printSlow(string text, int speed) {
    auto tp = chrono::steady_clock::now();
    for (char letter : text) {
        cout << letter << std::flush;
        tp += std::chrono::milliseconds(50 / speed);
        std::this_thread::sleep_until(tp);
    }
    tp += std::chrono::milliseconds(500 / speed);
    std::this_thread::sleep_until(tp);
    cout << endl;
}

void dialogue::pause(int pauseTime, int speed) {
    auto tp = chrono::steady_clock::now();
    tp += std::chrono::milliseconds(pauseTime / speed);
    std::this_thread::sleep_until(tp);
}

void dialogue::dots(int dots, int speed) {
    auto tp = chrono::steady_clock::now();
    for (int i = 0; i < dots; i++) {
        cout << ". " << std::flush;
        tp += std::chrono::milliseconds(500 / speed);
        std::this_thread::sleep_until(tp);
    }
    tp += std::chrono::milliseconds(500 / speed);
    std::this_thread::sleep_until(tp);
    cout << endl;
}

string dialogue::prompt( string text) {
    cout << text << endl;
    string choice;
    cin >> choice;
    string parsOut = pars(choice);
    return parsOut;
}

string dialogue::pars(string text) {
    if (text == "y" || text == "yes" || text == "Y" || text == "YES") {
        text = "y";
    }
    if (text == "n" || text == "no" || text == "N" || text == "NO") {
        text = "n";
    }
    return text;
}

	