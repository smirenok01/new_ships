#include "State.h"


State::State()
{
}


State::~State()
{
}


InGameState::InGameState()
{
	player1 = new Human(true,1);
	player2 = new AI(false,2);
}
InGameState::~InGameState()
{

}

void InGameState::Init()
{
	GameLoop();
}
void InGameState::Cleanup()
{
	system("cls");
}

void InGameState::Pause()
{
	flag = false;
}
void InGameState::Resume()
{
	GameLoop();
}

bool InGameState::Step(Player* p1,Player* p2)
{
	Render r;
	r.Show(p1->GetMap());
	r.ShowMyFieldEnemy(p2->GetMap());
	//p1->MyMove(p2->GetMap());
	if (p1->MyMove(p2->GetMap())!=NULL)
	{
		this->Pause();

		return false;//!
	}
	if (p1->GetIsWin())//smir
	{		
		std::cout << "Player"<<p1->GetNunbPlayer()<< "is Win!!!";
		return false;
	}
	p1->SetMove(false);
	p2->SetMove(true);
	return true;
}

void InGameState::GameLoop()
{
	flag = true;
	while (flag)
	{
		if (player1->GetMove())
		{
			flag=Step(player1, player2);
		}
		else if (player2->GetMove())
		{
			flag = Step(player2, player1);
		}
		else
		{
			cout << "ERROR";
		}
		system("cls");
	}
	
}

MenyState::MenyState()
{

}
MenyState::~MenyState()
{

}

void MenyState::Init()
{

}
void MenyState::Cleanup()
{

}

void MenyState::Pause()
{

}
void MenyState::Resume()
{

}