#include "Item.h"

Item::Item(string name, string description, bool isPickeable, bool isStoreable)
{
	itemName = name;
	itemDescription = description;
	pickeable = isPickeable;
	storeable = isStoreable;
}

Item::~Item()
{
}

string Item::Name()
{
	return itemName;
}

string Item::Description()
{
	return itemDescription;
}

void Item::SetDescription(string description)
{
	itemDescription = description;
}

bool Item::IsPickeable()
{
	return pickeable;
}

bool Item::IsStoreable()
{
	return storeable;
}
