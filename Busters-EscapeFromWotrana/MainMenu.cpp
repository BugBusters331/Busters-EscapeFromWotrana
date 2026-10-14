#include "MainMenu.h"
#include <iostream>

using namespace std;

void mainMenu::displayMenu()
{
	int input;
	cout << "*----------------------------------------------*" << endl;
	cout << "|          Bug Busters Studios Presents:       |" << endl;
	cout << "|***************ESCAPE FROM WOTRANA************|" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|				  Press 1 to Start              |" << endl;
	cout << "|			   Press 2 for User Manual          |" << endl;
	cout << "|                Press 3 to Exit               |" << endl;
	cout << "*----------------------------------------------*" << endl;

	if (input == 1)
	{
		// Start the game
	}

	else if (input == 2)
	{
		// Display the user manual
	}
	
	else if (input == 3)
	{
		// Exit the program
	}


}

void mainMenu::displayUserManual()
{
	cout << "*----------------------------------------------*" << endl;
	cout << "|******************USER MANUAL*****************|" << endl;
	cout << "|                                              |" << endl;
	cout << "*----------------------------------------------*" << endl;
}

