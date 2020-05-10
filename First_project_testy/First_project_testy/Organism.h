class Map;

class Organism {
	int x, y;
	char symbol;
public:
	/*Map & map;*/
	Organism(/*Map & map ,*/const int& x,const int& y,  const char& symbol);
	~Organism();
	const int Get_X();
	const int Get_Y();
	const char Get_Symbol();

	void Set_X(int new_x);
	void Set_Y(int new_y);

	//virtual void action() = 0;

	/*const bool operator <(const Organism& s2) const;
	const bool operator ==(const Organism& s2) const;*/
};