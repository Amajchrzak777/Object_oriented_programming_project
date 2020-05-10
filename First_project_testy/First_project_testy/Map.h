#include <vector>
#include "Organism.h"


class Organism;

class Map {
	std::vector<Organism*> all_organisms;

	void check_errors(int& x);
protected:
	int coordinate_x;
	int coordinate_y;
	const int width = 15;
	const int height = 15;
	char fields[30][30];
	int upper, lower, right, left;
	int dimension = 1;
	int history_x_coordinate[10000];
	int history_y_coordinate[10000];
	int ile = 0;
	int klawisz;
	char pd = 188, pg = 187, lg = 201, ld = 200, poz = 205, pio = 186;
	char kierunek;
public:
	void draw_the_map();
	//void dimension_of_board();
	void game();
	void give_the_coordinates();
	void initialize_fields();
	void key_to_play();
	void move();
	void use_key();

	const void add_organism(Organism* new_organism);
};

//class Move {
//public:
//
//};