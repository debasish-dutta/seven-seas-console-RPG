#include "armour.h"

dArr<std::string> Armour::names;

void Armour::initNames()
{
	Armour::names.push("Robe-of-Fallen-Angel");
	Armour::names.push("Dark-Fiend's-Leather-Jacket");
	Armour::names.push("Leviethan's-Cloak");
	Armour::names.push("Suit-of-Demon-Blood");
	Armour::names.push("ColdShadow-Body-Armour");
	Armour::names.push("Invincible-Dragon-Armour");
}

Armour::Armour() : Item() {
	this->defence = 0;
}

Armour::Armour(int level, int rarity) :Item(itemTypes::ARMOUR, level, rarity) {
	this->defence = rand() % (level * (rarity+1));
	this->defence += (rarity + 1) * 5;
	this->setName(Armour::names[rand() % Armour::names.size()]);
	
	if(rarity == 3)
		this->defence += level * 5;
	else if (rarity == 4)
		this->defence += level * 10;
}


Armour::Armour(int defence, std::string name, int level, int buyValue, int sellvalue, int rarity) :  Item(itemTypes::ARMOUR, name, level, buyValue, sellvalue, rarity) {
	this->defence = defence;
}

Armour::~Armour() {
	
}

Armour* Armour::clone()const {
	return new Armour(*this);
}

std::string Armour::toString()const {
	std::string str = this->getName()
	+ " | Lvl: "
	   + std::to_string(this->getLevel())
	   + " | Rarity: "
	   + std::to_string(this->getRarity())
	   + " | Defence: " + std::to_string(this->defence);
	
	return str;
}

std::string Armour::toStringSave()const
{
	std::string str =
		std::to_string(this->getItemType())
		+ " "
		+ this->getName()
		+ " "
		+ std::to_string(this->getLevel())
		+ " "
		+ std::to_string(this->getRarity())
		+ " "
		+ std::to_string(this->getBuyValue())
		+ " "
		+ std::to_string(this->getSellValue())
		+ " "
		+ std::to_string(this->defence)
		+ " ";

	return str;
}
