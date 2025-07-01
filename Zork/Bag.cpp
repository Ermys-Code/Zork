#include "Bag.h"

Bag::Bag(string name, string description, bool isPickeable, bool isStoreable) : Item(name, description, isPickeable, isStoreable)
{
	
}

Bag::Bag(string name, string description, bool isPickeable, bool isStoreable, vector<Item*> itemList) : Item(name, description, isPickeable, isStoreable)
{
	items = itemList;
}

vector<Item*> Bag::GetItems()
{
	return items;
}

void Bag::AddItem(Item* item)
{
	if(item->IsStoreable()) items.push_back(item);
}

void Bag::RemoveItem(Item* item)
{
	if (item == nullptr) return;

	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i]->Name() == item->Name())
		{
			items.erase(items.begin() + i);
			return;
		}
	}
}

