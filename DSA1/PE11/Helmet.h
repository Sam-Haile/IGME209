#pragma once
#include "Item.h"
class Helmet :
    public Item
{
public:
    Helmet();
    Helmet(std::string name, int damage, int weight, int durability);
};

