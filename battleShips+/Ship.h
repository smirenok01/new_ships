#pragma once
class Ship
{
private:
	int numDecks;
	bool isDeadShip;
	bool *Decks;
public:
	Ship(){}
	int GetNumDecks();
	bool GetDeck(int i);
	void SetDeck(int i, bool b);
	Ship(int numDeck, bool b);
	bool GetIsDeadShip();
	void SetIsDeadShip(bool b);
	~Ship();
};

