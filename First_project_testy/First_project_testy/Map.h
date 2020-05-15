#include <vector>
#include "Sheep.h"

class Organism;

class Map {
	std::vector<Organism*> all_organisms;

	void check_errors(int& x);
protected:
	int coordinate_x;
	int coordinate_y;
	
	int upper, lower, right, left;
	int dimension = 1;
	int history_x_coordinate[10000];
	int history_y_coordinate[10000];
	int ile = 0;
	int klawisz;
	char pd = 188, pg = 187, lg = 201, ld = 200, poz = 205, pio = 186;
	char kierunek;
	char fields[30][30];
	char new_fields[30][30];
public:
	const int width = 15;
	const int height = 15;
	void draw_the_map();
	void draw_the_map_new();
	//void dimension_of_board();
	void game();

	void initialize_fields();

	const int get_size_h();
	const int get_size_w();


	const int Get_Field(const int& x, const int& y);
	const void Set_Field(const int& x, const int& y, const char& symbol);

	const void add_organism(Organism* new_organism);
	const void do_round();
};

