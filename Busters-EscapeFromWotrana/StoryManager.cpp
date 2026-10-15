#include "StoryManager.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>


using namespace std;

void dialogue::print(const string& text) {
    cout << text;
    cout << endl;
}

void dialogue::printSlow(const string& text) {
    auto tp = chrono::steady_clock::now();
    for (char letter : text) {
        cout << letter << std::flush;
        tp += std::chrono::milliseconds(50);
        std::this_thread::sleep_until(tp);
    }
    tp += std::chrono::milliseconds(500);
    std::this_thread::sleep_until(tp);
    cout << endl;
}

void dialogue::pause(int pauseTime) {
    auto tp = chrono::steady_clock::now();
    tp += std::chrono::milliseconds(pauseTime);
    std::this_thread::sleep_until(tp);
}

void dialogue::dots(int dots) {
    auto tp = chrono::steady_clock::now();
    for (int i = 0; i < dots; i++) {
        cout << ". " << std::flush;
        tp += std::chrono::milliseconds(500);
        std::this_thread::sleep_until(tp);
    }
    tp += std::chrono::milliseconds(500);
    std::this_thread::sleep_until(tp);
    cout << endl;
}

string dialogue::prompt(const string& text) {
    cout << text << endl;
    string choice;
    cin >> choice;
    return choice;
}

	