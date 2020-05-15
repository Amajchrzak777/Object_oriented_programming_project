#include "Organism.h"

class Organism;

class Map;
class Animal;

class Animal : public Organism {
public:
	Animal(Map& map, const int& strength, const int& x, const int& y, const char& symbol);
	~Animal();
	virtual void action() = 0;
};