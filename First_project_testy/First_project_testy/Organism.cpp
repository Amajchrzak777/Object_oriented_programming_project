#include <iostream>
#include "Organism.h"

Organism::Organism(Map & map, const int& x, const int& y,const char& symbol)
	: map(map), x(x), y(y), symbol(symbol)
{
}

Organism::~Organism()
{
}

const int Organism::Get_X()
{
	return this->x;
}

const int Organism::Get_Y()
{
	return this->y;
}

const char Organism::Get_Symbol()
{
	return this->symbol;
}

void Organism::Set_X(int new_x)
{
	this->x = new_x;
}

void Organism::Set_Y(int new_y)
{
	this->y = new_y;	
}

//const bool Organism::operator<(const Organism& s2) const {
//    if (this->initiative == s2.initiative)
//        return this->age < s2.age;
//    else
//        return this->initiative < s2.initiative;
//}
//
//const bool Organism::operator==(const Organism& s2) const {
//    if (this->initiative == s2.initiative)
//        return this->age == s2.age;
//    else
//        return this->initiative == s2.initiative;
//}