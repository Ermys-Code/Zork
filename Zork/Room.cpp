#include "Room.h"

Room::Room(string name, string description, vector<Item*> items, vector<Character*> characters, vector<Exit*> exits)
{
    roomName = name;
    roomDescription = description;
    roomItems = items;
    roomCharacters = characters;
    roomExits = exits;
}

string Room::Name()
{
    return roomName;
}

string Room::Description()
{
    return roomDescription;
}

vector<Item*> Room::Items()
{
    return roomItems;
}

void Room::AddItem(Item* item)
{
    roomItems.push_back(item);
}

void Room::RemoveItem(Item* item)
{
    if (item == nullptr) return;

    for (size_t i = 0; i < roomItems.size(); i++)
    {
        if (roomItems[i]->Name() == item->Name())
        {
            roomItems.erase(roomItems.begin() + i);
            return;
        }
    }
}

vector<Character*> Room::Characters()
{
    return roomCharacters;
}

void Room::AddCharacter(Character* character)
{
    roomCharacters.push_back(character);
}

void Room::RemoveCharacter(Character* character)
{
    if (character == nullptr) return;

    for (size_t i = 0; i < roomCharacters.size(); i++)
    {
        if (roomCharacters[i]->Name() == character->Name())
        {
            roomCharacters.erase(roomCharacters.begin() + i);
            return;
        }
    }
}

vector<Exit*> Room::Exits()
{
    return roomExits;
}

void Room::AddExit(Exit* exit)
{
    roomExits.push_back(exit);
}

void Room::RemoveExit(Exit* exit)
{
    if (exit == nullptr) return;

    for (size_t i = 0; i < roomExits.size(); i++)
    {
        if (roomExits[i]->Name() == exit->Name())
        {
            roomExits.erase(roomExits.begin() + i);
            return;
        }
    }
}
