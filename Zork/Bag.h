#pragma once

#include "Item.h"
#include <vector>

class Bag : public Item
{
private:
	vector<Item*> items;
public:
	Bag(string name, string description, bool isPickeable, bool isStoreable);
	Bag(string name, string description, bool isPickeable, bool isStoreable, vector<Item*> itemList);

	vector<Item*> GetItems();
	void AddItem(Item* item);
	void RemoveItem(Item* item);
};

