#ifndef PLAYER_H
#define PLAYER_H

#include"STLIBINCLUDE.h"
#include "inventory.h"

// using namespace std;

class Player
{
    private:

        std::string name;
	
		Inventory inventory;
		Weapon weapon;
		Armour armour;
	
		int xPos;
		int yPos;
	
		int distancetravelled;
        
        int Exp;
        int Lvl;
        int Hp;
        int maxHp; 
        int Atk;
        int expReq;
		int Acc;
		int Armor;
		int Coins;
    
    public:
        Player();
		Player(std::string name, int distancetravelled, int Exp,
		   int Lvl, int Hp, int maxHp, int Atk,
		   int expReq, int Acc, int Armor, int Coins);
        virtual ~Player();

		void initialize(const std::string name);
		void printStats() const;
		std::string getAsString() const;
		std::string getInvAsString(bool shop = false);
		std::string getInvAsStringSave();
		void levelUp();
		void updateStats();
		
		void equipItem(unsigned index);
		inline void resetHP() { this->Hp = this->maxHp; }
		void addItem(const Item &item) { this->inventory.addItem(item); }
		void removeItem(const int index);
		const Item& getItem(const int index);
	
	
		// Accessors
		inline const std::string& getName() const { return this->name;}
		inline const int& getX() const { return this->xPos;}
		inline const int& getY() const { return this->yPos;}
		inline const int& getDist() const { return this->distancetravelled;}
		inline const int& getLvl() const { return this->Lvl;}
		inline const int& getExp() const { return this->Exp;}
		inline const int& getexpReq() const { return this->expReq;}
		inline const int& getHp() const { return this->Hp;}
		inline const int& getmaxHp() const { return this->maxHp;}
		inline const int& getAtk() const { return rand() % (this->Atk + this->weapon.getDamageMin()) + (this->Atk + this->weapon.getDamageMax()); }
		inline const int& getAcc() const { return this->Acc;}
		inline const int& getArmour() const { return this->Armor;}
		inline const int& getExtraArmour() const { return rand() % (this->Armor + this->armour.getDefence()) + (this->Armor + this->armour.getDefence()); }
		inline const int& getCoins() const { return this->Coins;}
		inline const bool isAlive() { return this->Hp > 0; }
	
		//Modifiers
		inline void setDistanceTravelled(const int& dist) { this->distancetravelled = dist;}
		inline void travel() { this->distancetravelled++; }
		inline void gainExp(const int Exp) { this->Exp += Exp; }
		inline void gainCoins(const int Coins) { this->Coins += Coins; }
		inline void payCoins(const int Coins) { this->Coins -= Coins; }
		void takeDamage(const int damage);
	
		inline void setWeapon(Weapon weapon) { this->weapon = weapon; }
		inline void setArmour(Armour armour) { this->armour = armour;}

};

#endif
