class Map;
class Move;
class Person;

class Map {
protected:
    int width;
    int height;
    char fields[30][30];
public:
    void initialize_fields();
    void draw_the_map(); //draw the map for the game
    void check_errors(int& x); //checking erros;
    void dimension_of_board();
    Map(int, int);
    Map();
    //void give_the_coordinates();
};

class Move : public Map {
    /*int x_before[];
    int y_before[];*/
    int how_many;
protected:
    int upper, lower, right, left;
public:
    void key_to_play();
    void move_of_human();
    Move();
};

class Person : public Map {
protected:
    int coordinate_x;
    int coordinate_y;
public:
    Person(int x_c, int y_c);
    void give_the_coordinates();
    Person(int);
};

#include "Objects.cpp"

