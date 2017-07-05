#pragma once
#include "Cell.h"
#include "Ship.h"
class Map
{
private:
	enum{ size = 10 };
	Cell field[10][10];
	Ship ships[size];
public:
	Map();
	int GetSize();
	void SetCell(Cell c, int x, int y);
	void SetShip(Ship s,int i);
	Cell* GetCell(int x, int y);
	Ship* GetShip(int i);
	bool isGameOver();
	~Map();
};

