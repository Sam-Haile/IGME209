#include "Helmet.h"

Helmet::Helmet() : Item("", 0, 0, 0)
{

}

Helmet::Helmet(std::string name, int damage, int weight, int durability)
	: Item(name, damage, weight, durability)
{

}