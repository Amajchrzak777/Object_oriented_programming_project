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
	m.add_organism(new Human(m,3, 3, 'H'));
	m.add_organism(new Sheep(m,5, 10, 'S'));
	m.game();
}
