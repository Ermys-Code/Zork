#pragma once

#include <string>

using namespace std;

class Item
{
private:
	string itemName;
	string itemDescription;
	bool pickeable;
	bool storeable;
public:
	Item(string name, string description, bool isPickeable, bool isStoreable);
	string Name();
	string Description();
	bool IsPickeable();
	bool IsStoreable();
};

