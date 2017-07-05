#pragma once
class Cell
{
private:
	int x;
	int y;
	bool isEmpty;
	int indexShip;
	int indexDeck;
	bool isHit;
public:
	Cell(){}
	Cell(int x, int y, bool b=true, int indShip=-1, int indDeck=-1, bool d=false);
	bool GetIsEmpty();
	int GetIndexDeck();
	void SetIndexDeck(int i);
	int GetIndexShip();
	void SetIndexShip(int i);
	void SetIsHit(bool b);
	void SetIsEmpty(bool b);
	bool GetIsHit();
	~Cell();
};

