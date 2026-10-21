#include "MainMenu.h"
#include <iostream>

using namespace std;

void mainMenu::displayMenu()
{
	cout << "*----------------------------------------------*" << endl;
	cout << "|          Bug Busters Studios Presents:       |" << endl;
	cout << "|***************ESCAPE FROM WOTRANA************|" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|                Press 1 to Start              |" << endl;
	cout << "|             Press 2 for User Manual          |" << endl;
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
	cout << "*----------------------------------------------*" << endl;
	cout << "|******************USER MANUAL*****************|" << endl;
	cout << "| Escape from Wotrana is a text-based adventure|" << endl;
	cout << "| game where you must venture through various  |" << endl;
	cout << "| regions of the distant planet of Wotrana in  |" << endl;
	cout << "| order to repair your damaged spaceship.      |" << endl;
	cout << "|**********************************************|" << endl;
	cout << "|                                              |" << endl;
	cout << "|                                              |" << endl;
	cout << "|                                              |" << endl;
	cout << "*----------------------------------------------*" << endl;
	
	

}

