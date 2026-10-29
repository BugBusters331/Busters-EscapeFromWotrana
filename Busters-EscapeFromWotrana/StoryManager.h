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
	int speedChoice();
	void print(string text);
	void printSlow( string text, int speed);
	void pause(int pauseTime, int speed);
	void dots(int dots, int speed);
	string prompt(string text);
	string pars(string text);
};