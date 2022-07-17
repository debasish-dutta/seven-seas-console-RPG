#include "monster.h"

Monster::Monster(int Lvl)
{
	this->Lvl = Lvl;
	this->maxHp = rand() % (this->Lvl*10) + (Lvl*2);
	this->Hp = this->maxHp;
	this->AtkMin = this->Lvl*1;
	this->AtkMax = this->Lvl*2;
	this->Armour = rand() % this->Lvl*5+1;
	this->Acc = rand() % this->Lvl*2+1;
	this->dropChance = rand() % 100 + 1;
}

Monster::~Monster(){

}

std::string Monster::getString()const
{
	return "Level: " + std::to_string(this->Lvl) + "\n" +
			"Hp: " + std::to_string(this->Hp) + " / " + std::to_string(this->maxHp) + "\n" +
			"Damage: " + std::to_string(this->AtkMin) + " ~ " + std::to_string(this->AtkMax) + "\n" +
			"Defence: " + std::to_string(this->Armour) + "\n" +
			"Accuracy: " + std::to_string(this->Acc) + "\n" +
			"Drop chance: " + std::to_string(this->dropChance) + "\n";
}

void Monster::takeDamage(int damage)
{
	this->Hp -= damage;

	if (this->Hp <= 0)
	{
		this->Hp = 0;
	}
}
