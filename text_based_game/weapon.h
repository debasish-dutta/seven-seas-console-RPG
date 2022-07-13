#ifndef WEAPON_H
#define WEAPON_H

#include"STLIBINCLUDE.h"
#include"item.h"

class Weapon : public Item
{
	private:
		int damageMin;
		int damageMax;
	public:
		Weapon();
		Weapon(int level, int rarity);
		Weapon(int damageMin, int DamageMax, std::string name, int level, int buyValue, int sellValue, int rarity);
		virtual ~Weapon();
		
		
		virtual Weapon* clone()const;//Pure virtual Func
		//Functions
		std::string toString()const;
		std::string toStringSave()const;
		
		//Accessors
		inline int getDamageMin()const { return this->damageMin; }
		inline int getDamageMax()const { return this->damageMax; }


		//Static
		static dArr<std::string> names;
		static void initNames();
	};

#endif
