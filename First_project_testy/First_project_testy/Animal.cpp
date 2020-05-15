#include "Map.h"


Animal::Animal(Map& map, const int& strength, const int& x, const int& y, const char& symbol) : Organism(map, strength, x, y, symbol)
{
}

Animal::~Animal()
{
}