#pragma once

#include <vector>
#include "Character.h"
#include "Item.h"
#include "Room.h"

class Player : public Character
{
private:
	int playerMaxHunger;
	int playerCurrentHunger;
	int playerMaxThirst;
	int playerCurrentThirst;
	vector<Item*> playerInventory;
	Room* playerCurrentRoom;

public:
	Player(string name, string description, int maxHunger, int currentHunger, int maxThirst, int currentThirst/*, Room* currentRoom*/);

	int MaxHunger();
	int CurrentHunger();
	int MaxThirst();
	int CurrentThirst();
	vector<Item*> Items();
	void AddItem(Item* item);
	void RemoveItem(Item* item);
	Room* CurrentRoom();
};

