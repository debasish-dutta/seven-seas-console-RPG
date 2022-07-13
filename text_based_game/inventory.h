#ifndef INVENTORY_H
#define INVENTORY_H

#include"STLIBINCLUDE.h"
#include "weapon.h"
#include "armour.h"

class Inventory {
		
		int cap;
        int noOfItems;
        Item **itemArr;
		
		void initialize(const int from = 0);
		void expand();
	
    public:
		Inventory();
		~Inventory();
		Inventory(const Inventory &obj);
	
		inline int size()const { return this->noOfItems;};
		Item& operator[](const int index);
		void operator=(const Inventory &obj);
	
		//functions
		void addItem(const Item &item);
		void removeItem(int index);

		inline void debugPrint() const {
			for (size_t i = 0; i< this->noOfItems; i++) {
				std::cout << this->itemArr[i]->debugPrint() << std::endl;
		}
	}
};






#endif
