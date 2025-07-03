#include <string>
#include "Exit.h"
#include "Room.h"
#include "Player.h"
#include "Scenario.h"

Scenario::Scenario()
{
    Room* room = new Room("name", "description", vector<Item*> {}, vector<Character*> {}, vector<Exit*> {});

    rooms.push_back(room);
}

vector<Room*> Scenario::GetRooms()
{
    return rooms;
}

Player* Scenario::GetPlayer()
{
    return player;
}
