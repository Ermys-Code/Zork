#include "Exit.h"
#include "Room.h"
#include "Character.h"
#include "Item.h"


Room::Room(string name, string description, vector<Item*> items, vector<Character*> characters)
{
    roomName = name;
    roomDescription = description;
    roomItems = items;
    roomCharacters = characters;
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

bool Room::HasItems()
{
    return roomItems.size() != 0;
}

void Room::ReadItems()
{
    if (roomItems.size() == 0) return;

    for (size_t i = 0; i < roomItems.size(); i++)
    {
        cout << "- " << roomItems[i]->Name() << "\n";
    }

    cout << "\n";
}

Exit* Room::HasExitOfDirection(string direction)
{
    for (size_t i = 0; i < roomExits.size(); i++)
    {
        if (roomExits[i]->HasDirection(direction, this)) return roomExits[i];
    }

    return nullptr;
}

Item* Room::GetItem(string name)
{
    for (size_t i = 0; i < roomItems.size(); i++)
    {
        if (ToLower(roomItems[i]->Name()) == name) return roomItems[i];
    }

    return nullptr;
}

Character* Room::GetCharacter(string name)
{
    for (size_t i = 0; i < roomCharacters.size(); i++)
    {
        if (ToLower(roomCharacters[i]->Name()) == name) return roomCharacters[i];
    }

    return nullptr;
}

bool Room::HasCharacters()
{
    return roomCharacters.size() > 0;
}

void Room::ReadCharacters()
{
    if (roomCharacters.size() == 0) return;

    for (size_t i = 0; i < roomCharacters.size(); i++)
    {
        cout << "- " << roomCharacters[i]->Name() << "\n";
    }

    cout << "\n";
}

bool Room::HasExits()
{
    return roomExits.size() > 0;
}

void Room::ReadExits()
{
    if (roomExits.size() == 0) return;

    int dir;

    for (size_t i = 0; i < roomExits.size(); i++)
    {
        dir = roomExits[i]->GetDirectionFromRoom(this);
        switch (dir)
        {
        case 1:
            cout << "- North\n";
            break;
        case 2:
            cout << "- South\n";
            break;
        case 3:
            cout << "- East\n";
            break;
        case 4:
            cout << "- West\n";
            break;
        }
    }
}