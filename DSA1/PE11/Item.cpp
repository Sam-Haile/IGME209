#include "Item.h"
#include <iostream>
using namespace std;


Item::Item()
{
	m_name = "Uknown";
	m_damage = 10;
	m_weight = 5;
	m_durability = 100;
}

Item::Item(std::string name, int damage, int weight, int durability)
{
	m_name = name;
	m_damage = damage;
	m_weight = weight;
	m_durability = durability;
}

void Item::print()
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Damage: " << m_damage << std::endl;
	std::cout << "Weight: " << m_weight << std::endl;
	std::cout << "Durability: " << m_durability << "\n" << std::endl;
}