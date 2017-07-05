#include "AbstractRender.h"


AbstractRender::AbstractRender()
{
}

void AbstractRender::Show(Map* m)
{
	for (int i = 0; i < m->GetSize(); i++)
	{
		for (int j = 0; j < m->GetSize(); j++)
		{

			bool b1 = m->GetCell(i, j)->GetIsEmpty();
			bool b2 = m->GetCell(i, j)->GetIsHit();
			int b3 = m->GetCell(i, j)->GetIndexShip();
			int b4 = m->GetCell(i, j)->GetIndexDeck();
			if (m->GetCell(i, j)->GetIsEmpty() && m->GetCell(i, j)->GetIsHit())
			{
				std::cout << "o";
			}
			else if (m->GetCell(i, j)->GetIsEmpty())
			{
				std::cout << ".";
			}
			else if (!m->GetCell(i, j)->GetIsEmpty() && m->GetCell(i, j)->GetIsHit())
			{
				std::cout << "x";
			}
			else if (!m->GetCell(i, j)->GetIsEmpty() && !m->GetCell(i, j)->GetIsHit())
			{
				std::cout << "s";
			}
			else
			{
				std::cout << "e";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void AbstractRender::ShowMyFieldEnemy(Map* m)
{
	for (int i = 0; i < m->GetSize(); i++)
	{
		for (int j = 0; j < m->GetSize(); j++)
		{
			if (m->GetCell(i, j)->GetIsHit() && m->GetCell(i, j)->GetIsEmpty())
			{
				std::cout << "o";
			}
			else if (!m->GetCell(i, j)->GetIsHit())
			{
				std::cout << ".";
			}
			else if (m->GetCell(i, j)->GetIsHit() && !m->GetCell(i, j)->GetIsEmpty())
			{
				std::cout << "x";
			}
			else
			{
				std::cout << "e";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
AbstractRender::~AbstractRender()
{
}


Render::Render()
{

}

void Render::Show(Map* m)
{
	AbstractRender::Show(m);
}

void Render::ShowMyFieldEnemy(Map* m)
{
	AbstractRender::ShowMyFieldEnemy(m);
}

Render::~Render()
{

}