#pragma once
#include "Item.h"
class Armor :
    public Item
{

public:
    Armor();
    Armor(std::string name, int damage, int weight, int durability);
};

