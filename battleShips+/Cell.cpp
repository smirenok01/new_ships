#include "Cell.h"



Cell::Cell(int x, int y, bool b, int indShip, int indDeck, bool d)
{
	this->x = x;
	this->y = y;
	this->isEmpty = b;
	this->indexShip = indShip;
	this->indexDeck = indDeck;
	this->isHit = d;
}

bool Cell::GetIsEmpty()
{
	return isEmpty;
}
int Cell::GetIndexDeck()
{
	return indexDeck;
}
void Cell::SetIndexDeck(int i)
{
	this->indexDeck = i;
}
void Cell::SetIndexShip(int i)
{
	this->indexShip = i;
}

void Cell::SetIsHit(bool b)
{
	this->isHit = b;
}

int Cell::GetIndexShip()
{
	return indexShip;
}

void Cell::SetIsEmpty(bool b)
{
	this->isEmpty = b;
}
bool Cell::GetIsHit()
{
	return isHit;
}
Cell::~Cell()
{
}
