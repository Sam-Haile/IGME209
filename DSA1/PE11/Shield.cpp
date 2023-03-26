#include "Shield.h"

Shield::Shield() : Item("", 0, 0, 0)
{

}

Shield::Shield(std::string name, int damage, int weight, int durability) : Item(name, damage, weight, durability) {
    
}