#ifndef SHOP_H
#define SHOP_H

#include"STLIBINCLUDE.h"

class Coins;
class Item;
class Weapon;
class Armor;

class Inventory {

        int noOfItems;
        Item **itemArr;

    public:
        Shop();
        ~Shop();
        Shop(const Inventory &obj);
        
        inline int size()const { return this->noOfItems; };

        void AddItem(const Item &item);

        void RemoveItem(int index);

        void Repair();


};






#endif