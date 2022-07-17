#ifndef MONSTER_H
#define MONSTER_H

#include"STLIBINCLUDE.h"

class Monster
{
	private:

	//	int Exp;
		int Lvl;
		int Hp;
		int maxHp;
		int AtkMin;
		int AtkMax;
		int Armour;
		int Acc;
		float dropChance;
	//	int expReq;
		
	public:
		Monster(int Lvl = 0);
		virtual ~Monster();

		// Functions
//		void levelUp();

//		inline void gainExp(const int Exp) { this->Exp += Exp; }
		inline bool isAlive() { return this->Hp > 0; }
		void takeDamage(int damage);
		std::string getString() const;

		// Accessors
		inline const int getLvl() const { return this->Lvl;}
		inline const int getHp() const { return this->Hp;}
		inline const int getmaxHp() const { return this->maxHp;}
		inline const int getAtkMin() const {return this->AtkMin;}
		inline const int getAtkMax() const {return this->AtkMax;}
		inline const int getAtk() const { return rand() % this->AtkMin + this->AtkMax;}
		inline const int getArmour() const { return this->Armour;}
		inline const int getAcc() const { return this->Acc;}
		inline int getExp()const { return this->Lvl * 100; }
};


#endif
