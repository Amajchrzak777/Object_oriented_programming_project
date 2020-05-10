#include "Map.h"

class Map;

class Human : public Map {
	int ss;
public:
	Human() {}
	char z = 'H';
	void move(char z);
	void give_the_coordinates(char z);
};
