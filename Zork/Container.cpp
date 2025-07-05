#include "Container.h"

Container::Container(string name, string description, bool isPickeable, bool isStoreable) : Item(name, description, isPickeable, isStoreable)
{
	
}

Container::Container(string name, string description, bool isPickeable, bool isStoreable, vector<Item*> itemList) : Item(name, description, isPickeable, isStoreable)
{
	items = itemList;
}

vector<Item*> Container::Items()
{
	return items;
}

void Container::AddItem(Item* item)
{
	if(item->IsStoreable()) items.push_back(item);
}

void Container::RemoveItem(Item* item)
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

void Container::ReadItems()
{
	cout << "Contains:\n";
	for (size_t i = 0; i < items.size(); i++)
	{
		cout << "- " << items[i]->Name() << "\n";
	}
}

bool Container::HasItems()
{
	return items.size() > 0;
}

Item* Container::GetItem(string name)
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (ToLower(items[i]->Name()) == name)
		{
			return items[i];
		}
	}

	return nullptr;
}

