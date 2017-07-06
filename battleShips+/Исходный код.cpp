#include "State.h"
#include"time.h"
#include "StateManager.h"
int main()
{
	srand(time(NULL));
	StateManager Game;
	State* inGame=new InGameState();
	Game.ChangeState(inGame);
	//
	return 0;
}