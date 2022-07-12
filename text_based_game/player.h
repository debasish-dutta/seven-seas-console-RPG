#ifndef PLAYER_H
#define PLAYER_H

#include"STLIBINCLUDE.h"
// using namespace std;
#include "characters.h"

class Weapon;
class Armor;


class Player : public Characters {
    
    private:
        std::string name;

        int Armour;
        int Coins;

	    Weapon equippedWeapon;
	    Armor equippedArmor;   


    public:
        Player();
        Player(std::string name, int exp,
		            int Lvl, int Atk, int Hp, int Armour, int Coins);
        virtual ~Player();

        void initialize(const std::string name);
        unsigned int GetXPToLevelUp(int Lvl);

        int GetLevel();
        int getMaxHp(int Lvl);
        inline const std::string& getName() const { return this->name; }
	    inline const int& getLevel() const { return this->Lvl; }
	    inline const int& getExp() const { return this->exp; }
		inline const int& getexpReq() const { return this->expReq;}
		inline const int& getHp() const { return this->Hp;}
		inline const int& getmaxHp() const { return this->maxHp;}
		inline const int& getAtk() const { return this->Atk;}
        inline const int getGold() const { return this->gold; }

        inline void gainExp(const int exp) { this->exp += exp; }
	    inline void gainGold(const int gold) { this->gold += gold; }
	    inline void payGold(const int gold) { this->gold -= gold; }
	    inline void resetHp() { this->hp = this->maxHp; }
	    
        void takeDamage(const int damage);
        void EquipWeapon(const Item &item) 
	    void EquipArmour(const int index);
}




#endif
