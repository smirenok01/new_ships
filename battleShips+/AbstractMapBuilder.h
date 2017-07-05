#pragma once
#include<iostream>
#include "Map.h"
#include<time.h>

using namespace std;


struct Coordinates
{
	int x;
	int y;
	bool v;
};

class AbstractMapBuilder
{
private:
	
public:
	AbstractMapBuilder();
	virtual Map BuildMap()=0;
	virtual~AbstractMapBuilder();
};

class MapBuilder : public AbstractMapBuilder
{
private:
	void StandShips(Map* m);
	void StandShip(Map* m, int indexShip);
	Coordinates GenerateCoordinates(Map* m, int indexShip);
	bool CheckShip(bool v, int x, int y, int numDecks, Map* m);
	void SetChangesOnField(Map* m, int indexShip, Coordinates coordinates);
	bool CheckOutOfBounds(int coordinate, int numDecks);
	bool ChecIsEmptyVertical(int x, int y, int numDecks, Map* m);
	bool ChecIsEmptyHorisontal(int x, int y, int numDecks, Map* m);

public:
	MapBuilder();
	Map BuildMap();
	~MapBuilder();
};

