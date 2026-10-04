#pragma once
class Chunks{
private:
	int board;
	int chunkx;
	int chunky;
public:
	Chunks();
	
	void drawChunks(int playerX, int playerY) const;

	bool isWalkable(int playerX, int playerY) const;
	bool isExit(int playerX, int playerY) const;

	int getChunkX() const;
	int getChunkY() const;

};

