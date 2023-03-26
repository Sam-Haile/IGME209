#include "Sword.h"

Sword::Sword() : Item("", 0, 0, 0)
{

}

Sword::Sword(std::string name, int damage, int weight, int durability) : Item(name, damage, weight, durability) {
   
}