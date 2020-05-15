#include "Map.h"
#include <time.h>
#include <Windows.h>

Sheep::Sheep(Map& map,const int& strength, const int& x, const int& y, const char& symbol) : Organism(map,strength, x, y, symbol)
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
		this->map.Set_Field(this->Get_X(), this->Get_Y(), ' ');
		this->Set_X(Get_X() - 1);
		if (this->Get_X() < 0)this->Set_X(Get_X() + 1);
		break;
	case 2:
		this->map.Set_Field(this->Get_X(), this->Get_Y(), ' ');
		this->Set_X(Get_X() + 1);
		if (this->Get_X() >= this->map.get_size_w()) this->Set_X(Get_X() - 1);
		break;
	case 3:
		this->map.Set_Field(this->Get_X(), this->Get_Y(), ' ');
		this->Set_Y(Get_Y() + 1);
		if (this->Get_Y() >= this->map.get_size_h()) this->Set_Y(Get_Y() - 1);
		break;
	case 4:
		this->map.Set_Field(this->Get_X(), this->Get_Y(), ' ');
		this->Set_Y(Get_Y() - 1);
		if (this->Get_Y() < 0) this->Set_Y(Get_Y() + 1);
		break;
	}
}