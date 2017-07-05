#include "Player.h"
#include "AbstractMapBuilder.h"
#include<iostream>
//#include"time.h"

Player::Player(bool b,int n)
{
	this->numberOfPlayer = n;
	this->isMove = b;
	isWin = false;
	x = 0;
	y = 0;
	MapBuilder mb;
	myMap = mb.BuildMap();
}
int Player::GetNunbPlayer()
{
	return this->numberOfPlayer;
}
void Player::SetMove(bool b)
{
	this->isMove = b;
}
bool Player::GetMove()
{
	return isMove;
}
void Player::SetMap(Map m)
{
	this->myMap = m;
}
void Player::SetX(int x)
{
	this->x = x;
}
void Player::SetY(int y)
{
	this->y = y;
}
int Player::GetX()
{
	return x;
}
int Player::GetY()
{
	return y;
}
bool Player::GetIsWin()
{
	return this->isWin;
}
bool Player::Move(Map* m, int x, int y)
{
	if (m->GetCell(x, y)->GetIsHit())//
	{
		//std::cout << "try again ";
		return true;
	}
	else
	{
		m->GetCell(x, y)->SetIsHit(true);
		if (m->GetCell(x, y)->GetIsEmpty())
		{
			return false;
		}
		else
		{
			m->GetShip(m->GetCell(x, y)->GetIndexShip())->SetDeck(m->GetCell(x, y)->GetIndexDeck(), false);
			if (m->GetShip(m->GetCell(x, y)->GetIndexShip())->GetIsDeadShip())///проверка убит ли корабль
			{
				m->GetShip(m->GetCell(x, y)->GetIndexShip())->SetIsDeadShip(true);
				if (m->isGameOver())//проверка убиты ли все корабли и закончена ли игра
				{
					isWin = true;////
					return true;
				}
				return true;
			}
			return true;
		}
	}

}

bool Player::isGameOver()
{
	return myMap.isGameOver();
}
Map* Player::GetMap()
{
	return &myMap;
}

int Player::GetCoordinateX()
{
	//srand(time(NULL));
	this->x = rand() % 10;
	return x;
}
int Player::GetCoordinateY()
{
	//srand(time(NULL));
	this->y = rand() & 10;
	return y;
}

Player::~Player()
{
}



Human::Human(bool b, int n) : Player(b,n)
{

}
int Human::GetNunbPlayer()
{
	return Player::GetNunbPlayer();
}

void Human::SetMove(bool b)
{
	Player::SetMove(b);
}
bool Human::GetMove()
{
	return Player::GetMove();
}
void Human::SetMap(Map m)
{
	Player::SetMap(m);
}
bool Human::GetIsWin()
{
	return Player::GetIsWin();
}
int Human::GetCoordinateX()
{
	int x;
	std::cout << "Player,please enter y coordinate : ";
	std::cin >> x;
	if ((char)x=='m')
	{
		return x;
	}
	Player::SetX(x);
	if (x>9 || x < 0)
	{
		std::cout << "You must enter value <9 and >0" << std::endl;
		GetCoordinateX();
	}
	return x;
}
int Human::GetCoordinateY()
{
	int y;
	std::cout << "Player,please enter x coordinate : ";
	std::cin >> y;
	if ((char)y == 'm')
	{
		return y;
	}
	Player::SetY(y);
	if (y>9 || y < 0)
	{
		std::cout << "You must enter value <9 and >0" << std::endl;
		GetCoordinateY();
	}

	return y;
}
int Human::MyMove(Map* mp)
{
	bool b = false;
	if (GetCoordinateX()=='m' || GetCoordinateY()=='m')
	{
		return 'm';
	}
	b = Player::Move(mp, this->GetX(), this->GetY());
	if (Player::GetIsWin())
	{
		return NULL;
	}
	if (b)
	{
		std::cout << "Please enter coordinates again" << std::endl;
		MyMove(mp);
	}
	return NULL;
}
Human::~Human()
{

}

AI::AI(bool b, int n) :Player(b,n)
{

}
int AI::GetNunbPlayer()
{
	return Player::GetNunbPlayer();
}
void AI::SetMove(bool b)
{
	Player::SetMove(b);
}
bool AI::GetMove()
{
	return Player::GetMove();
}
void AI::SetMap(Map m)
{
	Player::SetMap(m);
}
bool AI::GetIsWin()
{
	return Player::GetIsWin();
}
int AI::GetCoordinateX()
{
	return Player::GetCoordinateX();
}
int AI::GetCoordinateY()
{
	return Player::GetCoordinateY();
}
int AI::MyMove(Map* mp)
{	
	bool b = false;

	b = Move(mp, GetCoordinateX(), GetCoordinateY());
	if (Player::GetIsWin())
	{
		return NULL;
	}
	if (b)
	{
		MyMove(mp);
	}
	return NULL;
}
AI::~AI()
{

}