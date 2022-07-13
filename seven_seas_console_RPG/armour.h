#ifndef ARMOUR_H
#define ARMOUR_H

#include"STLIBINCLUDE.h"
#include"item.h"

class Armour : public Item
{
	private:
		int defence;
	public:
		Armour();
		Armour(int level, int rarity);
		Armour(int defence, std::string name, int level, int buyValue, int sellValue, int rarity);
		virtual ~Armour();
		
	
		virtual Armour* clone() const; //Pure virtual Func
		
		//Functions
		std::string toString()const;
		std::string toStringSave()const;
	
		//Accessors
		inline int getDefence() const { return this->defence;}
	
		//Static
		static dArr<std::string> names;
		static void initNames();
};

#endif
