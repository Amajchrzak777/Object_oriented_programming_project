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
	m.add_organism(new Human(m,20,3, 3, 'H'));
	m.add_organism(new Sheep(m,15,5, 10, 'A'));
	m.add_organism(new Sheep(m, 10, 7, 7, 'B'));
	m.add_organism(new Sheep(m, 11, 1, 1, 'C'));
	m.add_organism(new Sheep(m, 11, 10, 10, 'D'));
	m.add_organism(new Sheep(m, 11, 6, 6, 'E'));
	m.game();
}
