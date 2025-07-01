#pragma once

#include <string>

using namespace std;

class Item
{
private:
	string itemName;		//Name of the item
	string itemDescription; //Description of the item
	bool pickeable;			//Indicates if the player can pick the item
	bool storeable;			//Indicates if the item can be stored in a bag

public:
	Item(string name, string description, bool isPickeable, bool isStoreable); //Constructor of the base class Item

	string Name();			//Returns the name of the item
	string Description();	//Returns the description of the item
	bool IsPickeable();		//Returns if the item is pickeable
	bool IsStoreable();		//Returns if the item is storeable
};

