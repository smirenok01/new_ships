#pragma once
#include<iostream>
#include "Map.h"

class AbstractRender
{
public:
	AbstractRender();
	virtual void Show(Map* m) = 0;
	virtual void ShowMyFieldEnemy(Map* m) = 0;
	~AbstractRender();
};

class Render : public AbstractRender
{
public:
	Render();
	void Show(Map* m);
	void ShowMyFieldEnemy(Map* m);
	~Render();
};

