#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "Human.h"


class Organism;

int main()
{
	int x1 = 5;
	int y1 = 5;
	const char w1 = 'W';
	srand(time(NULL));
	Map m;
	//m.dimension_of_board();
	m.key_to_play();
	m.initialize_fields();
	m.give_the_coordinates();
	m.add_organism(new Organism(x1, y1, w1));
	m.game();
}
