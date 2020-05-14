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
    }
}

void Map::draw_the_map() {
    std::cout << lg;
    for (int i = 0; i <		width; ++i) {
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


void Map::initialize_fields() {
    for (int i = 1; i < height-1; ++i) {
        for (int j = 1; j < width-1; ++j) {
            fields[j][i] = ' ';
			new_fields[j][i] = ' ';
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
	ile++;
	std::vector<Organism*> organism_tmp = all_organisms;
	for (auto n : organism_tmp) n->action();

	for (auto o : all_organisms) {
		fields[o->Get_X()][o->Get_Y()] = ' ';
	}
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

