#include <iostream>
#include <conio.h>
#include "Map.h"

Human::Human(Map& map, const int& x, const int& y, const char& symbol) : Organism(map, x, y, symbol)
{
}

Human::~Human()
{
}

const void Human::key(){
	upper = 224;
	if (upper == 224) upper += 72;
	//std::cout << "Lower" << std::endl;
	lower = 224;
	if (lower == 224) lower += 80;
	//std::cout << "Right" << std::endl;
	right = 224;
	if (right == 224) right += 77;
	//std::cout << "Left" << std::endl;
	left = 224;
	if (left == 224) left += 75;
}

void Human::action()
{
	this->map.draw_the_map_new();
	key();
	while (true) {
		
		if (_kbhit()) {
			klawisz = _getch();
			if (klawisz == 224) klawisz += _getch();
			if (klawisz == 0) klawisz -= _getch();

			if (klawisz == lower) this->Set_Y(Get_Y() + 1);
			if (klawisz == upper) this->Set_Y(Get_Y() - 1);
			if (klawisz == left) this->Set_X(Get_X() - 1);
			if (klawisz == right) this->Set_X(Get_X() + 1);
	
			if (this->Get_X() >= this->map.get_size_w()) this->Set_X(Get_X() - 1);
			if (this->Get_X() < 0) this->Set_X(Get_X() + 1);
			if (this->Get_Y() >= this->map.get_size_h()) this->Set_Y(Get_Y() - 1);
			if (this->Get_Y() < 0) this->Set_Y(Get_Y() + 1); 
			return;
		}
	}
}
