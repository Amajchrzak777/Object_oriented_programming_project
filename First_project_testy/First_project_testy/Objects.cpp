#include "Classes.h"
#include "includes.h"

void Map::draw_the_map() {
    for (;;) {
        ile++;
        history_x_coordinate[ile] = coordinate_x;
        history_y_coordinate[ile] = coordinate_y;
        //kasuje poprzednie H
        fields[history_x_coordinate[ile - dimension]][history_y_coordinate[ile - dimension]] = 'p';
        system("cls");
        //rysuje górn¹ ramkê
        std::cout << lg;
        for (int i = 0; i < width; ++i) {
            std::cout << poz << poz;
        }
        std::cout << pg;
        for (int i = 0; i < height; ++i) {
            //rysuje lewy bok
            std::cout << std::endl << pio;
            for (int j = 0; j < width; ++j) {
                if (fields[j][i] == 'p')std::cout << "  ";
                if (fields[j][i] == 'H')std::cout << " H";
            }
            //rysuje prawy bok
            std::cout << pio;
        }
        
        std::cout << std::endl;
        std::cout << ld;
        //rysuje doln¹ ramkê
        for (int i = 0; i < width; ++i) {
            std::cout << poz << poz;
        }
        std::cout << pd;
        Sleep(500);
        use_key();
        move();
    }
}

void Map::check_errors(int& x) {
    while ((x < 5) || (x > 30)) {
        std::cout << "wrong scope ! try again";
        std::cin >> x;
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

void Map::give_the_coordinates() {
    coordinate_x = rand() % height;
    coordinate_y = rand() % width;
    fields[coordinate_x][coordinate_y] = 'H';
}

void Map::initialize_fields() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            fields[j][i] = 'p';
        }
    }
}

void Map::key_to_play() {
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

void Map::move() {
    if(kierunek == 'd')coordinate_y++;
    if (kierunek == 'g')coordinate_y--;
    if (kierunek == 'l')coordinate_x--;
    if (kierunek == 'p')coordinate_x++;
    if (coordinate_x == width) coordinate_x--/* = 0*/;
    if (coordinate_x == -1) coordinate_x++/*width - 1*/;
    if (coordinate_y == height) coordinate_y--/* = 0*/;
    if (coordinate_y == -1) coordinate_y++/*height - 1*/;
    fields[coordinate_x][coordinate_y] = 'H';
}

void Map::use_key() {
    if (_kbhit()) {
        klawisz = _getch();
        if (klawisz == 224) klawisz += _getch();
        if (klawisz == 0) klawisz -= _getch();

        if (klawisz == upper) kierunek = 'g';
        if (klawisz == lower) kierunek = 'd';
        if (klawisz == left) kierunek = 'l';
        if (klawisz == right) kierunek = 'p';
    }
}
