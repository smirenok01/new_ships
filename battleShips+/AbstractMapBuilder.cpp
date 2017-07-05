#include "AbstractMapBuilder.h"


AbstractMapBuilder::AbstractMapBuilder()
{
}

Map AbstractMapBuilder::BuildMap()
{
	Map myMap;
	
	for (int i = 0; i < myMap.GetSize(); i++)
	{
		for (int j = 0; j < myMap.GetSize(); j++)
		{
			
			myMap.SetCell(Cell(i, j, true, -1, -1, false), i, j);
		}
	}
	int typeShips[10] = { 4, 3, 3, 2, 2, 1, 1, 1, 1, 1 };
	for (int i = 0; i < 10; i++)
	{
		
		myMap.SetShip(Ship(typeShips[i], false), i);
	}
	return myMap;
}

AbstractMapBuilder::~AbstractMapBuilder()
{
}


MapBuilder::MapBuilder()
{

}

Map MapBuilder::BuildMap()
{
	Map myMap;

	for (int i = 0; i < myMap.GetSize(); i++)
	{
		for (int j = 0; j < myMap.GetSize(); j++)
		{
			
			myMap.SetCell(Cell(i, j, true, -1, -1, false), i, j);
		}
	}
	int typeShips[10] = { 4, 3, 3, 2, 2, 1, 1, 1, 1, 1 };
	for (int i = 0; i < myMap.GetSize(); i++)
	{
		myMap.SetShip(Ship(typeShips[i], false), i);
	}

	StandShips(&myMap);

	return myMap;
}

void MapBuilder::StandShips(Map* m)
{
	for (int i = 0; i < m->GetSize(); i++)
	{
		StandShip(m,i);
	}

}

void MapBuilder::StandShip(Map* m,int indexShip)
{
	Coordinates c=GenerateCoordinates(m, indexShip);

	SetChangesOnField(m,indexShip,c);
}

Coordinates MapBuilder::GenerateCoordinates(Map* m,int indexShip)
{
	//srand(time(NULL));
	bool flag = true;
	int x;
	int y;
	bool v;
	while (flag)
	{
		x = rand() % 10;
		y = rand() % 10;
		v = rand() % 2;
		if (CheckShip(v, x, y,m->GetShip(indexShip)->GetNumDecks() ,m))
		{
			flag = false;
		}
	}
	Coordinates coordinates;
	coordinates.v = v;
	coordinates.x = x;
	coordinates.y = y;
	return coordinates;
}

void MapBuilder :: SetChangesOnField(Map* m, int indexShip, Coordinates coordinates)
{
	for (int i = 0; i < m->GetShip(indexShip)->GetNumDecks(); i++)
	{
		if (coordinates.v)/////!!!!!переписать
		{
			m->GetCell(coordinates.x, coordinates.y)->SetIsEmpty(false);
			m->GetCell(coordinates.x, coordinates.y)->SetIndexShip(indexShip);
			m->GetCell(coordinates.x, coordinates.y)->SetIndexDeck(i);
		
			coordinates.y++;
		}
		else
		{
			m->GetCell(coordinates.x, coordinates.y)->SetIsEmpty(false);
			m->GetCell(coordinates.x, coordinates.y)->SetIndexShip(indexShip);
			m->GetCell(coordinates.x, coordinates.y)->SetIndexDeck(i);
		
			coordinates.x++;
		}
	}
}

bool MapBuilder::CheckShip(bool v, int x, int y, int numDecks,Map* m)
{
	if (v)
	{
		return CheckOutOfBounds(y, numDecks) & ChecIsEmptyVertical(x, y, numDecks,m);
	}
	else
	{
		return CheckOutOfBounds(x, numDecks) & ChecIsEmptyHorisontal(x, y, numDecks,m);
	}
}

bool MapBuilder::CheckOutOfBounds(int coordinate,int numDecks)
{
	if ((coordinate + numDecks)<10 && (coordinate + numDecks)>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MapBuilder::ChecIsEmptyVertical(int x,int y,int numDecks,Map* m)
{
	int x1 = x;
	int y1 = y - 1;
	for (int i = 0; i < numDecks + 2; i++)
	{
		if (!m->GetCell(x1, y1)->GetIsEmpty() || !m->GetCell(x1 - 1, y1)->GetIsEmpty() || !m->GetCell(x1+1, y1)->GetIsEmpty())
		{
			return false;
		}
		y1++;
	}
	return true;
}

bool MapBuilder::ChecIsEmptyHorisontal(int x, int y, int numDecks, Map* m)
{
	int x1 = x - 1;
	int y1 = y;
	for (int i = 0; i < numDecks + 2; i++)
	{
		if (!m->GetCell(x1, y1)->GetIsEmpty() || !m->GetCell(x1, y1+1)->GetIsEmpty() || !m->GetCell(x1, y1-1)->GetIsEmpty())
		{
			return false;
		}
		x1++;
	}
	return true;
}


MapBuilder::~MapBuilder()
{

}