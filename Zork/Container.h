#pragma once

#include <iostream>
#include <vector>
#include "Item.h"

class Container : public Item
{
private:
	vector<Item*> items; //List of pointers to items that represents the inventory inside the container

public:
	Container(string name, string description, bool isPickeable, bool isStoreable);							//Constructor of the class Container with no items inside
	Container(string name, string description, bool isPickeable, bool isStoreable, vector<Item*> itemList);	//Constructor of the class Container with items inside

	vector<Item*> Items();			//Returns a list of pointers, where each pointer points to one element that is inside the bag
	void AddItem(Item* item);		//Adds the recived item pointer to the items list
	void RemoveItem(Item* item);	//Removes the recived item pointer from the items list
	void ReadItems();				//Prints a list of all the items that the container has in his inventory
};

