#include "ShipInspection.h"
#include "StoryManager.h"
#include <iostream>

using namespace std;

ShipInspection::ShipInspection() {
	cells = 0;
	sparks = 0;
	pipes = 0;
}

void ShipInspection::inspectShip(int speed) {
	dialogue first;

	first.printSlow("Scanning ship for damage...", speed);

	cout << "************************" << endl;
	cout << "	SHIP DAMAGE REPORT" << endl;
	cout << "************************" << endl;
	cout << " ENGINE STATUS: DAMAGED" << endl;
	cout << "************************" << endl;

	cout << "Required Repair Materials:" << endl;
	cout << "Cell: " << cells << "/4" << endl;
	cout << "Spark: " << sparks << "/3 "<< endl;
	cout << "Pipe: " << pipes << "/2" << endl;

}


//Will be able to update collected repair materials when connected to inventory system
void ShipInspection::updateMaterials(int newCells, int newSparks, int newPipes) {
	cells = newCells;
	sparks = newSparks;
	pipes = newPipes;
}

void ShipInspection::inspectExterior(int speed) {
	dialogue first;

	first.printSlow("Scanning ship exterior for damage...", speed);

	cout << "*********************************" << endl;
	cout << "	SHIP EXTERIOR DAMAGE REPORT" << endl;
	cout << "*********************************" << endl;
	cout << "     ANTENNA STATUS: DAMAGED" << endl;
	cout << "       WING STATUS: DAMAGED" << endl;
	cout << "      GLASS STATUS: DAMAGED" << endl;
	cout << "*********************************" << endl;

	cout << "Required Repair Materials:" << endl;
	cout << "To be determined." << endl;
}
