// Adam Majchrzak 17.04.2020r.
// Object_oriented_programming_project

#include <iostream>
#include <cstdlib>

class Map;


class Map {
    int width;
    int height;
public:
    void draw_the_map(); //draw the map for the game
    void check_errors(int& x); //checking erros
};


int main()
{
    Map draw;
    draw.draw_the_map();
}

void Map::check_errors(int& x) {
    while ((x < 10) || (x > 70)) {
        std::cout << "wrong scope ! try again";
        std::cin >> x;
    }
}


void Map::draw_the_map() {
    std::cout << "Enter the width the scope is [10, 70]";
    std::cin >> width;
    check_errors(width);
    std::cout << "Enter the height the scope is [10,70]";
    std::cin >> height; 
    check_errors(height);
    system("cls");
    for (int i = 0; i < width; ++i) {
        std::cout << "--";
    }
    for (int i = 0; i < height; ++i) {
        std::cout << std::endl <<"|";
        for (int j = 0; j < (width - 1); ++j) {
            std::cout << "  ";
        }
        std::cout << "|";
    }
    std::cout << std::endl;
    for (int i = 0; i < width; ++i) {
        std::cout << "--";
    }
}