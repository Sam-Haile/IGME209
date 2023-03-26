#pragma once
#include "Item.h"
class Shield :
    public Item
{
public:
    Shield();
    Shield(std::string name, int damage, int weight, int durability);
};

