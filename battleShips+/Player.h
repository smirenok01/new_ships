#pragma once
#include "Map.h"
class Player
{
private:
	int numberOfPlayer;
	bool isMove;
	Map myMap;
	int x;
	int y;
	bool isWin;
public:
	Player(bool b, int n);
	virtual int GetNunbPlayer()=0;
	virtual void SetMove(bool b) = 0;
	virtual bool GetMove() = 0;
	bool Move(Map* m, int x, int y);
	virtual int GetCoordinateX()=0;
	virtual int GetCoordinateY()=0;
	virtual bool GetIsWin()=0;
	virtual int MyMove(Map* mp)=0;
	bool isGameOver();
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
	Map* GetMap();
	virtual void SetMap(Map m);

	virtual ~Player();
};

class Human : public Player
{
public:
	Human(bool b, int n);
	void SetMap(Map m);
	int GetCoordinateX();
	int GetCoordinateY();
	int MyMove(Map* mp);
	bool GetIsWin();
	void SetMove(bool b);
	bool GetMove();
	int GetNunbPlayer();
	~Human();
};

class AI : public Player
{
public:
	AI(bool b, int n);
	void SetMap(Map m);
	int GetCoordinateX();
	int GetCoordinateY();
	int MyMove(Map* mp);
	bool GetIsWin();
	void SetMove(bool b);
	bool GetMove();
	int GetNunbPlayer();
	~AI();
};