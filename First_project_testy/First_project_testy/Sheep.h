#include "Human.h"

class Organism;

class Map;

class Sheep : public Organism {
public:
	Sheep(Map& map, const int& x, const int& y, const char& symbol);
	~Sheep();
	void action() override;
private:
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();
};
