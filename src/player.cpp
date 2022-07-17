#include "player.h"

Player::Player() {
	this->xPos = 0;
	this->yPos = 0;
	
	this->distancetravelled = 0;
	
	this->name = "";
	this->Lvl = 0;
	this->Exp = 0;
	this->Hp = 0;
	this->maxHp = 0;
	this->Atk = 0;
	this->expReq = 0;
	this->Acc = 0;
	this->Armor = 0;
	this->Coins = 0;
}

Player::Player(std::string name, int distancetravelled, int Lvl, 
				int Exp, int Hp, int maxHp, int Atk, 
				int Acc, int Armor, int Coins, int expReq) {
	
	this->distancetravelled = distancetravelled;
	
	this->name = name;
	this->Lvl = Lvl;
	this->Exp = Exp;
	this->Hp = Hp;
	this->maxHp = maxHp;
	this->Atk = Atk;
	this->expReq = expReq;
	this->Acc = Acc;
	this->Armor = Armor;
	this->Coins = Coins;
}

Player::~Player() {
	
}

void Player::initialize(const std::string name) {
	
	this->xPos = 0;
	this->yPos = 0;
	
	this->distancetravelled = 0;
	
	this->name = name;
	this->Lvl = 1;
	this->Exp = 0;
	this->Hp = 10;
	this->maxHp = pow(10, this->Lvl);
	this->Atk = pow(2, this->Lvl);
	this->expReq = static_cast<int>((50/3)*((pow(Lvl,3) - 6*pow(Lvl,2)) + (15*Lvl) - 10));
	this->Acc = static_cast<int>(pow(1.5, this->Lvl));
	this->Armor = pow(5, this->Lvl);
	this->Coins = 10;
	
	this->updateStats();
}

void Player::printStats() const {
	std::cout << "= Player Sheet =" << std::endl;
	std::cout << "= Name: " << this->name << std::endl;
	std::cout << "= Level: " << this->Lvl << std::endl;
	std::cout << "= Exp: " << this->Exp << std::endl;
	std::cout << "= Hp: " << this->Hp << "/" << this->maxHp << std::endl;
	std::cout << "= Atk: " << this->Atk << std::endl;
	std::cout << "= Accuracy: " << this->Acc << std::endl;
	std::cout << "= Armour: " << this->Armor << std::endl;
	std::cout << "= Coins: " << this->Coins << std::endl;
	std::cout << "= Exp to next Level: " << this->expReq << std::endl;
	std::cout << std::endl;
}

std::string Player::getAsString() const
{
	return name + " "
	+ std::to_string(distancetravelled) + " "
	+ std::to_string(Lvl) + " "
	+ std::to_string(Exp) + " "
	+ std::to_string(Hp) + " "
	+ std::to_string(maxHp) + " "
	+ std::to_string(Atk) + " "
	+ std::to_string(Acc) + " "
	+ std::to_string(Armor) + " "
	+ std::to_string(Coins) + " "
	+ std::to_string(expReq) + " ";
}

std::string Player::getInvAsString(bool shop)
{
	std::string inv;

	for (int i = 0; i < this->inventory.size(); i++)
	{
		if (shop)
		{
			inv += std::to_string(i) + ": " + this->inventory[i].toString() + "\n" + " - Sell value: "
				+ std::to_string(this->inventory[i].getSellValue()) + "\n";
		}
		else
		{
			inv += std::to_string(i) + ": " + this->inventory[i].toString() + "\n";
		}
	}

	return inv;
}

std::string Player::getInvAsStringSave()
{
	std::string inv;

	for (int i = 0; i < this->inventory.size(); i++)
	{
		if(this->inventory[i].getItemType() == itemTypes::WEAPON)
			inv += this->inventory[i].toStringSave();
	}

	inv += "\n";

	for (int i = 0; i < this->inventory.size(); i++)
	{
		if (this->inventory[i].getItemType() == itemTypes::ARMOUR)
			inv += this->inventory[i].toStringSave();
	}

	return inv;
}

void Player::levelUp() {
	if(this->Exp >= this->expReq) {
		this->Exp -= this->expReq;
		this->Lvl++;
		this->expReq = static_cast<int>((50/3)*((pow(Lvl,3) -
						6*pow(Lvl,2)) + (15*Lvl) - 10));
		this->updateStats();
		std::cout << "YOU ARE NOW LEVEL " << this->Lvl << "!" << "\n\n";
	}
	else {
		std::cout << "NOT ENOUGH EXP!" << "\n\n";
	}
}

void Player::updateStats()
{
	this->expReq = static_cast<int>(
		(50 / 3)*((pow(Lvl, 3)
			- 6 * pow(Lvl, 2))
			+ 17 * Lvl - 12)) + 100;
	this->maxHp = this->Lvl*10;
	this->Atk = this->Lvl*2;
	this->Armor = this->Lvl*5;
	this->Acc = static_cast<int>((this->Lvl)*1.5);
	this->Hp = this->maxHp;
}

void Player::takeDamage(const int damage)
{
	this->Hp -= damage;

	if (this->Hp <= 0)
	{
		this->Hp = 0;
	}
}

void Player::equipItem(unsigned index)
{
	if (index < 0 || index >= this->inventory.size())
	{
		std::cout << "No valid item selected!" << "\n\n";
	}
	else
	{
		Weapon *w = nullptr;
		w = dynamic_cast<Weapon*>(&this->inventory[index]);

		Armour *a = nullptr;
		a = dynamic_cast<Armour*>(&this->inventory[index]);

		//Is weapon
		if (w != nullptr)
		{
			if (this->weapon.getRarity() >= 0)
				this->inventory.addItem(this->weapon);
			this->weapon = *w;
			this->inventory.removeItem(index);
		}
		else if (a != nullptr)
		{
				if (this->armour.getRarity() >= 0)
					this->inventory.addItem(this->armour);
				this->armour = *a;
				this->inventory.removeItem(index);
		}
		else
		{
			std::cout << "ERROR EQUIP ITEM, ITEM IS NOT Armour OR WEAPON!";
		}
	}
}

void Player::removeItem(const int index)
{
	if (index < 0 || index >= this->inventory.size())
		std::cout << "ERROR, NOT POSSIBLE TO REMOVE ITEM, removeItem Character" << "\n\n";
	else
	{
		this->inventory.removeItem(index);
	}
}

const Item& Player::getItem(const int index)
{
	if (index < 0 || index >= this->inventory.size())
	{
		std::cout << "ERROR, NOT POSSIBLE TO REMOVE ITEM, getItem Character" << "\n\n";
		throw("ERROR OUT OF BOUNDS, GETITEM CHARACTER");
	}

	return this->inventory[index];
}
