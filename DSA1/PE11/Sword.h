#pragma once
#include "Item.h"
class Sword :
    public Item
{
public:
    Sword();
    Sword(std::string name, int damage, int weight, int durability);
};

