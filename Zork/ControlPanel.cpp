#include "ControlPanel.h"

ControlPanel::ControlPanel(string name, string description, bool isPickeable, bool isStoreable, Character* enemy) : Item(name, description, isPickeable, isStoreable)
{
	hasBeenActivated = false;
	enemyToPlace = enemy;
}

void ControlPanel::ActivatePanel()
{
	hasBeenActivated = true;
}

bool ControlPanel::IsActive()
{
	return hasBeenActivated;
}

void ControlPanel::SetRoom(Room* room)
{
	roomForEnemy = room;
}

Room* ControlPanel::GetRoom()
{
	return roomForEnemy;
}

Character* ControlPanel::GetEnemy()
{
	return enemyToPlace;
}
