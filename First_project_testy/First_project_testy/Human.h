#include "Organism.h"


class Organism;

class Map;

class Human : public Organism {
	int upper, lower, right, left, klawisz;
	char kierunek;
public:
	Human(Map& map,const int& strength, const int& x, const int& y, const char& symbol);
	~Human();
	
	const void key();
	void action() override;
};
