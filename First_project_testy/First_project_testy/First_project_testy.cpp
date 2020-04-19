// First_project_testy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "includes.h"
#include "Classes.h"


int main()
{
	srand(time(NULL));
	Map* m = new Map();
	m->dimension_of_board();
	m->key_to_play();
	m->initialize_fields();
	m->give_the_coordinates();
	m->draw_the_map();
}
