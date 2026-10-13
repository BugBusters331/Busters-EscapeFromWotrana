#include "MainMenu.h"
#include <iostream>

using namespace std;

void mainMenu::displayMenu()
{
	cout << "*----------------------------------------------*" << endl;
	cout << "|          Bug Busters Studios Presents:       |" << endl;
	cout << "|***************ESCAPE FROM WOTRANA************|" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|				  Press 1 to Start              |" << endl;
	cout << "|			   Press 2 for User Manual          |" << endl;
	cout << "|                Press 3 to Exit               |" << endl;
	cout << "*----------------------------------------------*" << endl;
}

int mainMenu::getuserChoice()
{
	cout << "Enter your choice: ";
	cin >> userChoice;

	return userChoice;
}

void mainMenu::displayUserManual()
{
	cout << "*---------------------------------*" << endl;
	cout << "|***Welcome to the User Manual!***|" << endl;
	cout << "||" << endl;
	cout << "||" << endl;
	cout << "||" << endl;
	cout << "||" << endl;
	cout << "||" << endl;
	cout << "|  Press 1 to return to Main Menu |" << endl;
}