#include "Classes.hpp"

//konstruktor classy Map: 
Map::Map(int h, int w) :height(h), width(w) {}
//konstruktor classy Move: 
Move::Move() 

{
}
//konstruktor classy Person: 
Person::Person(int x_c, int y_c) : coordinate_x(x_c), coordinate_y(y_c) {}

//metoda inicjalizuje puste pola na ca³ej planszy
void Map::initialize_fields() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            fields[30][30] = 'p';
        }
    }
}

//sprawdza czy nie wychodzê poza zakres maksymalnej i minimalnej liczy pól
void Map::check_errors(int& x) {
    while ((x < 5) || (x > 30)) {
        std::cout << "wrong scope ! try again";
        std::cin >> x;
    }
}

//rysuje mapê
void Map::draw_the_map() {
    Move* object = new Move();
    Person* human = new Person(width, height);
    dimension_of_board();
    human -> give_the_coordinates();
    object -> key_to_play();
    for (;;) {
        system("cls");
        for (int i = 0; i < width; ++i) {
            std::cout << "--";
        }
        for (int i = 0; i < height; ++i) {
            std::cout << std::endl << "|";
            for (int j = 0; j < (width - 1); ++j) {
                if (fields[j][i] == 'p')std::cout << "  ";
                else if (fields[j][i] == 'H')std::cout << " H";
                else std::cout << "  ";
            }
            std::cout << "|";
        }
        std::cout << std::endl;
        for (int i = 0; i < width; ++i) {
            std::cout << "--";
        }
        Sleep(500);
    }
}

void Map::dimension_of_board() {
    std::cout << "Enter the width the scope is [5, 30]";
    std::cin >> width;
    check_errors(width);
    std::cout << "Enter the height the scope is [5,30]";
    std::cin >> height;
    check_errors(height);
}

//nadaje wspó³rzêdne graczowi human
void Person::give_the_coordinates() {
    this->height = height;
    this->width = width;
    coordinate_x = rand() % height;
    coordinate_y = rand() % width;
    fields[coordinate_x][coordinate_y] = 'H';

}

//gracz wybiera przyciski do grania 
void Move::key_to_play() {
    std::cout << "Enter key which you want to play: " << std::endl;
    std::cout << "Upper" << std::endl;
    upper = _getch();
    if (upper == 224) upper += _getch();
    if (upper == 0) upper -= _getch();

    std::cout << "Lower" << std::endl;
    lower = _getch();
    if (lower == 224) lower += _getch();
    if (lower == 0) lower -= _getch();

    std::cout << "Right" << std::endl;
    right = _getch();
    if (right == 224) right += _getch();
    if (right == 0) right -= _getch();

    std::cout << "Left" << std::endl;
    left = _getch();
    if (left == 224) left += _getch();
    if (left == 0) left -= _getch();
}