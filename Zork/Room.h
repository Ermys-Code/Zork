#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"
#include "Exit.h"

using namespace std;

class Room
{
private:
	string roomName;					//The name of the room
	string roomDescription;				//The description of the room
	vector<Item*> roomItems;			//The items inside the room
	vector<Character*> roomCharacters;	//The characters inside the room
	vector<Exit*> roomExits;			//The exits that the room has

public:
	Room(string name, string description, vector<Item*> items, vector<Character*> characters, vector<Exit*> exits); //Constructor of the Room class

	string Name();								//Returns the name of the room
	string Description();						//Returns the description of the room
	vector<Item*> Items();						//Returns all the items that the room has
	void AddItem(Item* item);					//Adds an item to the room
	void RemoveItem(Item* item);				//Removes an item from the room
	vector<Character*> Characters();				//Returns all the characters that the room has
	void AddCharacter(Character* character);	//Adds a character to the room
	void RemoveCharacter(Character* character);	//Removes a character from the room
	vector<Exit*> Exits();						//Returns all the exits that the room has
	void AddExit(Exit* exit);					//Adds an exit to the room
	void RemoveExit(Exit* exit);				//Removes an exit from the room
};

