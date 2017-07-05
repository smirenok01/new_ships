#include "Ship.h"

Ship::Ship(int numDeck, bool b)
{
	this->isDeadShip = b;
	this->numDecks = numDeck;
	Decks = new bool[numDeck];
	for (int i = 0; i < numDeck; i++)
	{
		Decks[i] = true;
	}
}
void Ship::SetIsDeadShip(bool b)
{
	this->isDeadShip = b;
}
bool Ship::GetIsDeadShip()
{
	for (int i = 0; i < this->numDecks; i++)
	{
		if (Decks[i])
		{
			return false;
		}
	}
	return true;
}

bool Ship::GetDeck(int i)
{
	return &Decks[i];
}

void Ship::SetDeck(int i, bool b)
{
	this->Decks[i] = b;
}
int Ship::GetNumDecks()
{
	return this->numDecks;
}

Ship::~Ship()
{
}
