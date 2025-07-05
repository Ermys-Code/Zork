#pragma once
#include "Item.h"
#include "Character.h"
#include "Room.h"

class ControlPanel : public Item
{
private:
	bool hasBeenActivated;
	Character* enemyToPlace;
	Room* roomForEnemy;

public:
	ControlPanel(string name, string description, bool isPickeable, bool isStoreable, Character* enemy);	//Constructor of the class Bag with no items inside

	void ActivatePanel();
	bool IsActive();
	void SetRoom(Room* room);
	Room* GetRoom();
	Character* GetEnemy();
};

