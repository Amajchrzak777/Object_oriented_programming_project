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

			
			/*if (klawisz == lower) kierunek = 'd';
			if (klawisz == upper) kierunek = 'g';
			if (klawisz == left) kierunek = 'l';
			if (klawisz == right) kierunek = 'p';*/
			return;
		}
	}
	/*if (kierunek == 'd')this->Set_Y(Get_Y() + 1);
	if (kierunek == 'g')this->Set_Y(Get_Y() - 1);
	if (kierunek == 'l')this->Set_X(Get_X() - 1);
	if (kierunek == 'p')this->Set_X(Get_X() + 1);*/
	//fields[Get_X()][Get_Y()] = 'H';
    /*if (this->Get_X == width) *this->Get_X = 0;
    if (coordinate_x == -1) coordinate_x = width - 1;
    if (coordinate_y == height) coordinate_y = 0;
    if (coordinate_y == -1) coordinate_y = height - 1;*/
}
