#pragma once

#include "Item.h"
#include <vector>

class Bag : public Item
{
private:
	vector<Item*> items; //List of pointers to items that represents the inventory inside the bag

public:
	Bag(string name, string description, bool isPickeable, bool isStoreable);							//Constructor of the class Bag with no items inside
	Bag(string name, string description, bool isPickeable, bool isStoreable, vector<Item*> itemList);	//Constructor of the class Bag with items inside

	vector<Item*> Items();			//Returns a list of pointers, where each pointer points to one element that is inside the bag
	void AddItem(Item* item);		//Adds the recived item pointer to the items list
	void RemoveItem(Item* item);	//Removes the recived item pointer from the items list
};

