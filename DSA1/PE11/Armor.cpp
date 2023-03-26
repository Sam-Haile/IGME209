#include "Armor.h"

Armor::Armor() : Item("", 0, 0, 0)
{

}

Armor::Armor(std::string name, int damage, int weight, int durability) : Item(name, damage, weight, durability) {
    // Do any additional initialization here
}