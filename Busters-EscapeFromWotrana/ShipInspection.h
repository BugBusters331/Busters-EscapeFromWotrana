#pragma once
class ShipInspection
{
private:
	int cells;
	int sparks;
	int pipes;


public:
	ShipInspection();

	void inspectShip(int speed);
	void updateMaterials(int newCells, int newSparks, int newPipes);
};

