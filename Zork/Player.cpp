#include "Player.h"

void Player::Go(vector<string> args)
{
	string direction = args[1];

	Room* room = playerCurrentRoom->HasExitOfDirection(direction);
	if(room != nullptr){
		playerCurrentRoom = room;
	}
	else
	{
		cout << "I can't go that way.";
	}
}

void Player::Help()
{
	cout << "\n";
	cout << "Help: Shows all commands\n";
	cout << "Inventory: Shows all the items on your inventory";
	cout << "Go <direction>: Moves to the specified direction. You can skip the word 'Go'\n";
	cout << "Take <item>: Takes the item from the location and stores in your inventory\n";
}

void Player::Take(vector<string> args)
{
	if (args.size() < 2) {
		cout << "I don't know what to take...\n";
		return;
	}

	Item* item = playerCurrentRoom->GetItem(args[1]);

	if (item == nullptr) {
		cout << "I can't find that here";
		return;
	}

	AddItem(item);
	playerCurrentRoom->RemoveItem(item);
	cout << item->Name() << " taken";
}

void Player::Inventory()
{
	if (playerInventory.size() == 0) {
		cout << "My inventory is empty\n";
		return;
	}

	for (size_t i = 0; i < playerInventory.size(); i++)
	{
		cout << playerInventory[i]->Name() << "\n";
	}
}

Player::Player(string name, string description, int maxHunger, int currentHunger, int maxThirst, int currentThirst, Room* currentRoom) : Character(name, description)
{
	playerMaxHunger = maxHunger;
	playerCurrentHunger = currentHunger;
	playerMaxThirst = maxThirst;
	playerCurrentThirst = currentThirst;
	playerCurrentRoom = currentRoom;
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

void Player::ExecuteCommand(vector<string> args)
{
	if (args[0] == "help") Help();
	else if (args[0] == "inventory") Inventory();
	else if (args[0] == "go") Go(args);
	else if (args[0] == "north") {
		args.push_back("north");
		Go(args);
	}
	else if (args[0] == "south") {
		args.push_back("south");
		Go(args);
	}
	else if (args[0] == "east") {
		args.push_back("east");
		Go(args);
	}
	else if (args[0] == "west") {
		args.push_back("west");
		Go(args);
	}
	else if (args[0] == "take") Take(args);
	else cout << "\nI can't do that";
}

void Player::ReadStatistics()
{
	cout << "Player stats:\n";
	cout << "Hunger: " << playerCurrentHunger << " / " << playerMaxHunger << "\n";
	cout << "Thirst: " << playerCurrentThirst << " / " << playerMaxThirst << "\n";
	cout << "\n";
}
