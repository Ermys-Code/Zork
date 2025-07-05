#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "GlobalFunctions.h"

class Exit;
class Item;
class Character;

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
	Room(string name, string description, vector<Item*> items, vector<Character*> characters); //Constructor of the Room class

	string Name();								//Returns the name of the room
	string Description();						//Returns the description of the room
	vector<Item*> Items();						//Returns all the items that the room has
	void AddItem(Item* item);					//Adds an item to the room
	void RemoveItem(Item* item);				//Removes an item from the room
	vector<Character*> Characters();			//Returns all the characters that the room has
	void AddCharacter(Character* character);	//Adds a character to the room
	void RemoveCharacter(Character* character);	//Removes a character from the room
	vector<Exit*> Exits();						//Returns all the exits that the room has
	void AddExit(Exit* exit);					//Adds an exit to the room
	bool HasItems();							//Returns if the room has items inside
	void ReadItems();							//Prints the name and the description of all the items in the room
	Exit* HasExitOfDirection(string direction);	//Returns the exit if this room has an exit to the specified direction
	Item* GetItem(string name);					//Search in the item list of the room and return the item that matches with the name
	Character* GetCharacter(string name);		//Search in the character list of the room and return the character that matches with the name
};

