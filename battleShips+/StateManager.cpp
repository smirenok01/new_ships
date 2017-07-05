#include "StateManager.h"


StateManager::StateManager()
{

	running = true;
}

void StateManager::PushState(State* state)
{
	if (!states.empty())
	{
		states.top()->Pause();
	}
	states.push(state);
	states.top()->Init();
}
void StateManager::PopState()
{
	if (!states.empty()) {
		states.top()->Cleanup();
		states.pop();
	}

	if (!states.empty()) {
		states.top()->Resume();
	}
}
void StateManager::ChangeState(State* state)
{
	// cleanup the current state
	if (!states.empty()) {
		states.top()->Cleanup();
		states.pop();
	}

	// store and init the new state
	states.push(state);
	states.top()->Init();
}
StateManager::~StateManager()
{
}
