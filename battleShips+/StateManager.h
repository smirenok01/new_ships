#pragma once
#include<stack>
#include "State.h"

class State;

class StateManager
{
private:
	stack<State*>states;
	bool running;	
public:
	void ChangeState(State* state);
	void PushState(State* state);
	void PopState();
	bool Running() { return running; }
	void Quit() { running = false; }
	StateManager();
	~StateManager();
};

