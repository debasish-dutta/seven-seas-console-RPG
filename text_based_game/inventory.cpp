#include "inventory.h"

Inventory::Inventory() {
	this->cap = 10;
	this->noOfItems = 0;
	this->itemArr = new Item*[cap];
	this->initialize();
}

Inventory::~Inventory() {
	for (size_t i = 0; i<this->noOfItems; i++) {
		delete this->itemArr[i];
	}
	delete[] this->itemArr;
}

Inventory::Inventory(const Inventory &obj) {
	this->cap = obj.cap;
	this->noOfItems = obj.noOfItems;
	this->itemArr = new Item*[this->cap];
	
	for(size_t i = 0; i< this->noOfItems; i++) {
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	
	initialize(this->noOfItems);
}

Item& Inventory::operator[](const int index) {
	if(index< 0 || index >= this->noOfItems)
		throw("BAD INDEX!!");
		
	return *this->itemArr[index];
}

void Inventory::operator=(const Inventory &obj)
{
	for (size_t i = 0; i < this->noOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;

	this->cap = obj.cap;
	this->noOfItems = obj.noOfItems;
	this->itemArr = new Item*[this->cap];

	for (size_t i = 0; i < this->noOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->noOfItems);
}

void Inventory::expand()
{
	this->cap *= 2;

	Item **tempArr = new Item*[this->cap];

	for (size_t i = 0; i < this->noOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initialize(this->noOfItems);
}

void Inventory::initialize(const int from) {
	for (size_t i = from; i<cap; i++) {
		itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item &item) {
	if(this->noOfItems >= this->cap) {
		expand();
	}
	this->itemArr[this->noOfItems++] = item.clone();
}

void Inventory::removeItem(int index) {
	if (index < 0 || index >= this->noOfItems)
		throw("OUT OF BOUNDS REMOVE ITEM INVENTORY");

	delete this->itemArr[index];
	this->itemArr[index] = this->itemArr[this->noOfItems - 1];
	this->itemArr[--this->noOfItems] = nullptr;
}
