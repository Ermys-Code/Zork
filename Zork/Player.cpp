#include "Player.h"

Player::Player(string name, string description, int maxHunger, int currentHunger, int maxThirst, int currentThirst) : Character(name, description)
{
	playerMaxHunger = maxHunger;
	playerCurrentHunger = currentHunger;
	playerMaxThirst = maxThirst;
	playerCurrentThirst = currentThirst;
}

int Player::MaxHunger()
{
	return playerMaxHunger;
}

int Player::CurrentHunger()
{
	return playerCurrentHunger;
}

int Player::MaxThirst()
{
	return playerMaxThirst;
}

int Player::CurrentThirst()
{
	return playerCurrentThirst;
}

vector<Item*> Player::Items()
{
	return playerInventory;
}

void Player::AddItem(Item* item)
{
	playerInventory.push_back(item);
}

void Player::RemoveItem(Item* item)
{
	if (item == nullptr) return;

	for (size_t i = 0; i < playerInventory.size(); i++)
	{
		if (playerInventory[i]->Name() == item->Name())
		{
			playerInventory.erase(playerInventory.begin() + i);
			return;
		}
	}
}

Room* Player::CurrentRoom()
{
	return playerCurrentRoom;
}
