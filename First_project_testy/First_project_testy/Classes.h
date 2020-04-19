class Map {
	void check_errors(int &x);
protected:
	int coordinate_x;
	int coordinate_y;
	int width;
	int height;
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
	void dimension_of_board();
	void give_the_coordinates();
	void initialize_fields();
	void key_to_play();
	void move();
	void use_key();
};

class Move {
public:

};