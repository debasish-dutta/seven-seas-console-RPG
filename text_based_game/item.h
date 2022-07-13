#ifndef ITEM_H
#define ITEM_H

#include"STLIBINCLUDE.h"

enum itemTypes {WEAPON = 0, ARMOUR = 1};

class Item
{
	private:
		int itemType;
		std::string name;
		int level;
		int sellValue;
		int buyValue;
		int rarity;
	public:
	Item();
	Item(int itemType, int level, int rarity);
	Item(int itemType, std::string name, int level, int sellValue, int buyValue, int rarity);
	virtual ~Item();
	
	inline std::string debugPrint() const {return this->name;}
	
	virtual Item* clone()const = 0; //virtual class
	virtual std::string toString()const = 0;
	virtual std::string toStringSave()const = 0;
	
	//Accessors
	const int& getItemType() const { return this->itemType;}
	const std::string& getName() const {return this->name;}
	const int& getLevel() const {return this->level;}
	const int& getBuyValue() const {return this->buyValue;}
	const int& getSellValue() const {return this->sellValue;}
	const int& getRarity() const {return this->rarity;}
	
	//Modifiers
	inline void setName(std::string name) { this->name = name; }

};

enum rarity {
	COMMON = 0,
	UNCOMMON,
	RARE,
	LEGENDARY,
	MYTH
};

#endif
