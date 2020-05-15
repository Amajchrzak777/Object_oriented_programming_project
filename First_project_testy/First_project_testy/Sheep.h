#include "Human.h"

class Organism;

class Map;

class Sheep : public Organism {
public:
	Sheep(Map& map,const int& strength, const int& x, const int& y, const char& symbol);
	~Sheep();
	void action() override;
};
