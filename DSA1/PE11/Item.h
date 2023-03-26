#pragma once
#include <string>
struct Item
{
	std::string m_name;
	int m_damage;
	int m_weight;
	int m_durability;
	Item();
	Item(std::string name, int damage, int weight, int durability);
	void print();
};

