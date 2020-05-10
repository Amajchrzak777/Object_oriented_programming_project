#include <iostream>
#include "Human.h"

Map m1(5,5);

void Human::move(char z) {
    if (m1.kierunek == 'd')m1.coordinate_y++;
    if (m1.kierunek == 'g')m1.coordinate_y--;
    if (m1.kierunek == 'l')m1.coordinate_x--;
    if (m1.kierunek == 'p')m1.coordinate_x++;
    if (m1.coordinate_x == m1.width) m1.coordinate_x = 0;
    if (m1.coordinate_x == -1) m1.coordinate_x = m1.width - 1;
    if (m1.coordinate_y == m1.height) m1.coordinate_y = 0;
    if (m1.coordinate_y == -1) m1.coordinate_y = m1.height - 1;
    m1.fields[m1.coordinate_x][m1.coordinate_y] = z;
}

void Human::give_the_coordinates(char z) {
    m1.dimension_of_board();
    m1.coordinate_x = rand() % m1.height;
    m1.coordinate_y = rand() % m1.width;
    m1.fields[m1.coordinate_x][m1.coordinate_y] = z;
}
