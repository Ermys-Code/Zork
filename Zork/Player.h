#pragma once

#include <vector>
#include "Character.h"
#include "Item.h"
#include "Room.h"

class Player : public Character
{
private:
	int playerMaxHunger;			//Maximum hunger of the player
	int playerCurrentHunger;		//Current hunger of the player
	int playerMaxThirst;			//Maximum thirst of the player
	int playerCurrentThirst;		//Current thirst of the player
	vector<Item*> playerInventory;	//List of item pointers that represents the player inventory
	Room* playerCurrentRoom;		//The room where the player currently is

	void Go(vector<string> args);
	void Help();
	void Take(vector<string> args);
	void Inventory();
	void Look();
	void Drop(vector<string> args);

public:
	Player(string name, string description, int maxHunger, int currentHunger, int maxThirst, int currentThirst, Room* currentRoom);	//Constructor of the Player class

	int MaxHunger();							//Returns the maximum hunger of the player
	int CurrentHunger();						//Returns the current hunger of the player
	int MaxThirst();							//Returns the maximum thirst of the player
	int CurrentThirst();						//Returns the current thirst of the player
	vector<Item*> Items();						//Returns all the items that the player has in his inventory
	void AddItem(Item* item);					//Adds an item to the inventory
	void RemoveItem(Item* item);				//Removes an item from the inventory
	Room* CurrentRoom();						//Returns the room where the player currently is
	void ExecuteCommand(vector<string> args);	//Decides wich action execute based on the command
	void ReadStatistics();
	Item* GetItem(string name);
};

