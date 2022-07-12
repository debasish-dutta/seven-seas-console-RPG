#include "characters.h"

Character::Character() {
	this->name = "";
	this->Exp = 0;
	this->Lvl = 0;
	this->Hp = 0;
	this->maxHp = 0;
	this->Atk = 0;
	this->expReq = 0;
}

Character::~Character() {
	
}

void Character::initialize(std::string name) {
	this->name = name;
	this->Exp = 0;
	this->Lvl = 0;
	this->Hp = 1;
	this->maxHp = 1;
	this->Atk = 1;
	this->expReq = Lvl*10;
}
