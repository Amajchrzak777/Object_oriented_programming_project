#include "Sheep.h"
#include <time.h>
#include <Windows.h>

Sheep::Sheep(Map& map, const int& x, const int& y, const char& symbol) : Organism(map, x, y, symbol)
{
}

Sheep::~Sheep()
{
}

void Sheep::action()
{
	int ran = rand() % 4 + 1;
	switch (ran) {
	case 1:
		this->MoveUp();
		break;
	case 2:
		this->MoveDown();
		break;
	case 3:
		this->MoveRight();
		break;
	case 4:
		this->MoveLeft();
		break;
	}
}

void Sheep::MoveUp()
{
	return this->Set_X(Get_X() - 1);
}

void Sheep::MoveDown()
{
	return this->Set_X(Get_X() + 1);
}

void Sheep::MoveRight()
{
	return this->Set_Y(Get_Y() + 1);
}

void Sheep::MoveLeft()
{
	return this->Set_Y(Get_Y() - 1);
}

