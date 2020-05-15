#include "Human.h"

class Organism;
class Animal;
class Map;

class Sheep : public Animal {
public:
	Sheep(Map& map,const int& strength, const int& x, const int& y, const char& symbol);
	~Sheep();
	void action() override;
};
