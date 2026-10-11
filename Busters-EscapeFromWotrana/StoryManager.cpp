#include "StoryManager.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>


using namespace std;

void dialogue::print(const string& text) {
    cout << text;
}

void dialogue::printSlow(const string& text) {
    auto tp = chrono::steady_clock::now();
    for (char letter : text) {
        cout << letter << std::flush;
        tp += std::chrono::milliseconds(100);
        std::this_thread::sleep_until(tp);
    }
}
	