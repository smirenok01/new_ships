#pragma once

#include "Player.h"
#include "AbstractRender.h"
#include "AbstractMapBuilder.h"


class State
{
public:
	State();
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual ~State();
};

class InGameState : public State
{
private:
	Player* player1;
	Player* player2;
	bool flag;

	
public:
	InGameState();
	~InGameState();

	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void GameLoop();
	bool Step(Player* p1, Player* p2);

};

class MenyState : public State
{
private:
	
public:
	MenyState();
	~MenyState();

	void Init();
	void Cleanup();

	void Pause();
	void Resume();
};