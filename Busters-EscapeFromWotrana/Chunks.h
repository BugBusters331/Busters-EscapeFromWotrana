#pragma once
#include <string>
#include <vector>
using namespace std;

class Chunks{
private:
	vector<string> board;
	int chunkX;
	int chunkY;
public:
	Chunks();
	
	void drawChunks(int playerX, int playerY) const;

	bool isWalkable(int playerX, int playerY) const;
	bool isExit(int playerX, int playerY) const;

	int getChunkX() const;
	int getChunkY() const;

};

