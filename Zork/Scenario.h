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

public:
	Scenario();	//The constructor of the scenario class

	vector<Room*> GetRooms();	//Returns a vector that contains all the rooms in the game
	Player* GetPlayer();		//Returns the player
	void DescribePlayerRoom();
	string AskForCommand();
};

