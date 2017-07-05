#include "Map.h"
#include<iostream>
#include<time.h>
using namespace std;

Map::Map()
{

}

void Map::SetCell(Cell c,int x,int y)
{
	field[x][y] = c;
	
}

void Map::SetShip(Ship s, int i)

{
	ships[i] = s;
}

int Map::GetSize()
{
	return this->size;
}

bool Map::isGameOver()
{
	for (int i = 0; i < size; i++)
	{
		if (!ships[i].GetIsDeadShip())
		{
			return false;
		}
	}
	return true;
}

Cell* Map::GetCell(int x, int y)
{
	return &field[x][y];
}

Ship* Map::GetShip(int i)
{
	return &ships[i];
}

Map::~Map()
{

}

