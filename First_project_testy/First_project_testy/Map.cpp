#include "Map.h"
#include "includes.h"

static void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x + 1;
	pos.Y = y + 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

void Map::game() {
    for (;;) {
		system("cls");
        draw_the_map();
        Sleep(100);
		do_round();
		move();
    }
}

void Map::draw_the_map() {
    ile++;
    history_x_coordinate[ile] = coordinate_x;
    history_y_coordinate[ile] = coordinate_y;
    //kasuje poprzednie H
    fields[history_x_coordinate[ile - dimension]][history_y_coordinate[ile - dimension]] = ' ';
    std::cout << lg;
    for (int i = 0; i < width; ++i) {
        std::cout << poz;
    }
    std::cout << pg;
    for (int i = 0; i < height; ++i) {
        //rysuje lewy bok
        std::cout << std::endl << pio;

        for (int j = 0; j < width; ++j) {
            std::cout << fields[j][i];
			new_fields[j][i] = fields[j][i];
        }
        //rysuje prawy bok
        std::cout << pio;
    }

    std::cout << std::endl;
    std::cout << ld;
    //rysuje doln¹ ramkê
    for (int i = 0; i < width; ++i) {
        std::cout << poz;
    }
    std::cout << pd;
}

void Map::draw_the_map_new()
{
	for (size_t yR = 0; yR < height; yR++) {
		for (size_t xR = 0; xR < width; xR++) {
			if (fields[yR][xR] != new_fields[yR][xR]) {
				gotoxy(xR, yR);
				std::cout << fields[yR][xR];
				new_fields[yR][xR] = fields[yR][xR];
		
			}
		}
	}
}

void Map::give_the_coordinates() {
    coordinate_x = rand() % height;
    coordinate_y = rand() % width;
    fields[coordinate_x][coordinate_y] = 'H';
}

void Map::initialize_fields() {
    for (int i = 1; i < height-1; ++i) {
        for (int j = 1; j < width-1; ++j) {
            fields[j][i] = ' ';
			new_fields[j][i] = ' ';
        }
    }
}

void Map::key_to_play() {
    std::cout << "Enter key which you want to play: " << std::endl;
    std::cout << "Upper" << std::endl;
    upper = 224;
    if (upper == 224) upper += 72;

    std::cout << "Lower" << std::endl;
    lower = 224;
    if (lower == 224) lower += 80;

    std::cout << "Right" << std::endl;
    right = 224;
    if (right == 224) right += 77;

    std::cout << "Left" << std::endl;
    left = 224;
    if (left == 224) left += 75;
}

void Map::move() {
	use_key();
    if (kierunek == 'd')coordinate_y++;
    if (kierunek == 'g')coordinate_y--;
    if (kierunek == 'l')coordinate_x--;
    if (kierunek == 'p')coordinate_x++;
    if (coordinate_x == width) coordinate_x = 0;
    if (coordinate_x == -1) coordinate_x = width - 1;
    if (coordinate_y == height) coordinate_y = 0;
    if (coordinate_y == -1) coordinate_y = height - 1;
    fields[coordinate_x][coordinate_y] = 'H';
}

void Map::use_key() {
    while (true) {
        if (_kbhit()) {
            klawisz = _getch();
            if (klawisz == 224) klawisz += _getch();
            if (klawisz == 0) klawisz -= _getch();

            if (klawisz == upper) kierunek = 'g';
            if (klawisz == lower) kierunek = 'd';
            if (klawisz == left) kierunek = 'l';
            if (klawisz == right) kierunek = 'p';
            return;
        }
    }
}

const int Map::get_size_h()
{
	return this->height;
}

const int Map::get_size_w()
{
	return this->width;
}

const void Map::add_organism(Organism* new_organism)
{
    all_organisms.push_back(new_organism);
    fields[new_organism->Get_X()][new_organism->Get_Y()] = new_organism->Get_Symbol();
}

const void Map::do_round()
{
	std::vector<Organism*> organism_tmp = all_organisms;
	for (auto n : organism_tmp) n->action();

	for (auto m : all_organisms) {
		if (fields[m->Get_X()][m->Get_Y()] != m->Get_Symbol())
			fields[m->Get_X()][m->Get_Y()] = m->Get_Symbol();
	}

}



//funkcje do użycia w przyszłosci

//void Map::check_errors(int& x) {
//    while ((x < 5) || (x > 30)) {
//        std::cout << "wrong scope ! try again";
//        std::cin >> x;
//    }
//}

//void Map::dimension_of_board() {
//    std::cout << "Enter the width the scope is [5, 30]";
//    std::cin >> width;
//    check_errors(width);
//    std::cout << "Enter the height the scope is [5,30]";
//    std::cin >> height;
//    check_errors(height);
//}

//void Map::key_to_play() {
//    std::cout << "Enter key which you want to play: " << std::endl;
//    std::cout << "Upper" << std::endl;
//    upper = _getch();
//    if (upper == 224) upper += _getch();
//    if (upper == 0) upper -= _getch();
//
//    std::cout << "Lower" << std::endl;
//    lower = _getch();
//    if (lower == 224) lower += _getch();
//    if (lower == 0) lower -= _getch();
//
//    std::cout << "Right" << std::endl;
//    right = _getch();
//    if (right == 224) right += _getch();
//    if (right == 0) right -= _getch();
//
//    std::cout << "Left" << std::endl;
//    left = _getch();
//    if (left == 224) left += _getch();
//    if (left == 0) left -= _getch();
//}

