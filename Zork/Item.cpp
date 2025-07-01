#include "Item.h"

Item::Item(string name, string description, bool isPickeable, bool isStoreable)
{
	itemName = name;
	itemDescription = description;
	pickeable = isPickeable;
	storeable = isStoreable;
}

string Item::Name()
{
	return itemName;
}

string Item::Description()
{
	return itemDescription;
}

bool Item::IsPickeable()
{
	return pickeable;
}

bool Item::IsStoreable()
{
	return storeable;
}
