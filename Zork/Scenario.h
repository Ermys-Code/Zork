#pragma once

#include <iostream>
#include <vector>
#include "Room.h"
#include "Player.h"

class Room;
class Player;

using namespace std;

class Scenario
{
private:
	vector<Room*> rooms;	//All the rooms of the game
	Player* player;			//The player

	string ToLower(string command);

public:
	Scenario();	//The constructor of the scenario class

	vector<Room*> GetRooms();						//Returns a vector that contains all the rooms in the game
	Player* GetPlayer();							//Returns the player
	void DescribePlayerRoom();						//Shows the name and the description of the show
	string AskForCommand();							//Ask the player for a command and returns it
	vector<string> ProcessCommand(string command);	//Separates a command into arguments
};

