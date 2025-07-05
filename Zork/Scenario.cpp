#include <string>
#include "Exit.h"
#include "Room.h"
#include "Player.h"
#include "Scenario.h"
#include "Consumable.h"
#include "Container.h"
#include "Usb.h"
#include "Weapon.h"
#include "ControlPanel.h"

Scenario::Scenario()
{
    Item* food = new Consumable("Food", "Cereal bar that doesn't expire.", true, true, Hunger, 10);
    Item* water = new Consumable("Water", "Water bottle with water that is always fresh.", true, true, Hunger, 10);
    Item* usb = new Usb("USB", "USB with a label that says code.", true, true, "3068");
    Item* bag = new Container("Bag", "Small bag to store things.", true, false, vector<Item*> {usb});
    Item* pistol = new Weapon("Pistol", "Small plasma pistol.", true, true, 10, 5);
    Item* computer = new Container("Computer", "Computer with an usb port.", false, false);
    Item* controlPanel = new ControlPanel("Panel", "Control panel used to restart the cryostasis capsules.", false, false);
    
    Room* cryostasisChamber = new Room("Cryostasis Chamber", "A room with 3 cryostasis capsules where your crewmates sleep.", vector<Item*> {}, vector<Character*> {});
    Room* diningRoom = new Room("Dining Room", "A rounded room with a table in the middle.", vector<Item*> {food}, vector<Character*> {});
    Room* roomCorridor = new Room("Room Corridor", "A small corridor with 3 separated rooms.", vector<Item*> {}, vector<Character*> {});
    Room* room1 = new Room("Room 1", "A small room. This is your room.", vector<Item*> {water}, vector<Character*> {});
    Room* room2 = new Room("Room 2", "A small room. This is the room of the captain.", vector<Item*> {bag}, vector<Character*> {});
    Room* room3 = new Room("Room 3", "A small room. This is the room of your crewmate.", vector<Item*> {pistol}, vector<Character*> {});
    Room* mainCorridor = new Room("Main Corridor", "A big corridor that connects the dining room with the laboratory and the control room.", vector<Item*> {}, vector<Character*> {});
    Room* laboratory = new Room("Laboratory", "A big laboratory to do experiments.", vector<Item*> {computer}, vector<Character*> {});
    Room* controlRoom = new Room("Control Room", "The control room of the spaceship", vector<Item*> {controlPanel}, vector<Character*> {});

    Exit* cryostasisDiningExit = new Exit("east", "west", diningRoom, cryostasisChamber);
    Exit* roomCorridorDiningExit = new Exit("north", "south", roomCorridor, diningRoom);
    Exit* roomCorridorRoom1Exit = new Exit("east", "west", roomCorridor, room1);
    Exit* roomCorridorRoom2Exit = new Exit("south", "north", roomCorridor, room2);
    Exit* roomCorridorRoom3Exit = new Exit("west", "east", roomCorridor, room3);
    Exit* mainCorridorDiningExit = new Exit("west", "east", diningRoom, mainCorridor);
    Exit* mainCorridorLaboratoryExit = new Exit("north", "south", mainCorridor, laboratory);
    Exit* mainCorridorControlRoomExit = new Exit("west", "east", mainCorridor, controlRoom);

    diningRoom->AddExit(cryostasisDiningExit);
    cryostasisChamber->AddExit(cryostasisDiningExit);
    diningRoom->AddExit(roomCorridorDiningExit);
    roomCorridor->AddExit(roomCorridorDiningExit);
    roomCorridor->AddExit(roomCorridorRoom1Exit);
    room1->AddExit(roomCorridorRoom1Exit);
    roomCorridor->AddExit(roomCorridorRoom2Exit);
    room2->AddExit(roomCorridorRoom2Exit);
    roomCorridor->AddExit(roomCorridorRoom3Exit);
    room3->AddExit(roomCorridorRoom3Exit);
    diningRoom->AddExit(mainCorridorDiningExit);
    mainCorridor->AddExit(mainCorridorDiningExit);
    mainCorridor->AddExit(mainCorridorLaboratoryExit);
    laboratory->AddExit(mainCorridorLaboratoryExit);
    mainCorridor->AddExit(mainCorridorControlRoomExit);
    controlRoom->AddExit(mainCorridorControlRoomExit);

   
    rooms.push_back(cryostasisChamber);
    rooms.push_back(diningRoom);
    rooms.push_back(roomCorridor);
    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(mainCorridor);
    rooms.push_back(laboratory);
    rooms.push_back(controlRoom);

    player = new Player("Player", "Player", 10, 5, 10, 5, diningRoom);
}

vector<Room*> Scenario::GetRooms()
{
    return rooms;
}

Player* Scenario::GetPlayer()
{
    return player;
}

void Scenario::DescribePlayerRoom()
{
    Room* currentRoom = player->CurrentRoom();
    cout << currentRoom->Name() << "\n";
    cout << currentRoom->Description() << "\n\n";
    if (currentRoom->HasItems()) {
        cout << "Items:\n";
        currentRoom->ReadItems();
    }
    player->ReadStatistics();
}

string Scenario::AskForCommand()
{
    string command;
    getline(cin, command);
    command = ToLower(command);
    return command;
}

vector<string> Scenario::ProcessCommand(string command)
{
    vector<string> args;
    const char* iterator = command.c_str();
    
    do 
    {
        const char* begin = iterator;

        while (*iterator != ' ' && *iterator)
        {
            iterator++;
        }

        args.push_back(string(begin, iterator));
    } while (0 != *iterator++);
    
    return args;
}
