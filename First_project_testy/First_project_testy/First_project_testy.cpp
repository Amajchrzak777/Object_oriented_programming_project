#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "Map.h"

class Map;
class Organism;
class Human;

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
	m.add_organism(new Human(m,3, 3, 'D'));
	m.add_organism(new Sheep(m, 5, 10, 'S'));
	m.game();
}
