#include "Animal.h"


class Organism;
class Animal;
class Map;

class Human : public Animal {
	int upper, lower, right, left, klawisz;
	char kierunek;
public:
	Human(Map& map,const int& strength, const int& x, const int& y, const char& symbol);
	~Human();
	
	const void key();
	void action() override;
};
