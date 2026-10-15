#pragma once
#include <string>
#include <thread>
#include <chrono>
using namespace std;

class StoryManager{
private:
	// Private member variables and methods can be declared here
public:
	// Public member variables and methods can be declared here
};

class dialogue {
public:
	void print(const string& text);
	void printSlow(const string& text);
	void pause(int pauseTime);
	void dots(int dots);
	string prompt(const string& text);
};