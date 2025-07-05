#include "Player.h"

void Player::Go(vector<string> args)
{
	string direction = args[1];

	Exit* exit = playerCurrentRoom->HasExitOfDirection(direction);

	if (exit->NeedCode()) {
		cout << "Insert the code: ";
		string code;
		getline(cin, code);
		if (code != exit->Code()) {
			cout << "Incorrect code\n";
			return;
		}
	}

	Room* room = exit->GetRoomOnDirection(direction);

	if(room != nullptr){
		playerCurrentRoom = room;
		cout << "\n\n";
		Look();
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
	cout << "Take <item>: Takes the item from the location and stores it in your inventory\n";
	cout << "Take <item> from <container>: Takes the item from the container and stores it in your inventory\n";
	cout << "Drop <item>: Drops the item from your inventory to the current location\n";
	cout << "Examine <item>: Examine the specified item\n";
	cout << "Store <item> in <container>: Stores the item in the container\n";
	cout << "Use <item> in <item>: Uses the first item in the second item\n";
}

void Player::Take(vector<string> args)
{
	if (args.size() < 2 || args.size() > 4) {
		cout << "I don't know what to take...\n";
		return;
	}

	if (args.size() == 2) {
		Item* item = playerCurrentRoom->GetItem(args[1]);

		if (item == nullptr) {
			cout << "I can't find that here";
			return;
		}

		if (!item->IsPickeable()) {
			cout << "I can't take that";
			return;
		}

		AddItem(item);
		playerCurrentRoom->RemoveItem(item);
		cout << item->Name() << " taken";

		return;
	}
	else if (args.size() == 4 && args[2] == "from") {
		Item* item;

		if (args[3] == "computer") {
			item = playerCurrentRoom->GetItem(args[3]);
		}
		else {
			item = GetItem(args[3]);
		}


		if (item == nullptr) {
			cout << "I don't have that";
			return;
		}

		Container* container = dynamic_cast<Container*>(item);
		if (container == nullptr) {
			cout << "I can't take nothing from here";
			return;
		}

		if (!container->HasItems()) {
			cout << "There is nothing here";
			return;
		}

		Item* itemToAdd = container->GetItem(args[1]);
		if (itemToAdd == nullptr) {
			cout << "I can't find that";
			return;
		}
		AddItem(itemToAdd);
		container->RemoveItem(itemToAdd);
		cout << itemToAdd->Name() << " taken";

		return;
	}
	else {
		cout << "I don't know what to take...\n";
	}
}

void Player::Inventory()
{
	if (playerInventory.size() == 0) {
		cout << "My inventory is empty\n";
		return;
	}

	for (size_t i = 0; i < playerInventory.size(); i++)
	{
		cout << "- " << playerInventory[i]->Name() << "\n";
	}
}

void Player::Look()
{
	cout << "\n" << playerCurrentRoom->Name() << "\n";
	cout << playerCurrentRoom->Description() << "\n\n";
	if (playerCurrentRoom->HasItems()) {
		cout << "Items:\n";
		playerCurrentRoom->ReadItems();
	}
	ReadStatistics();
}

void Player::Drop(vector<string> args)
{
	if (args.size() < 2) {
		cout << "I don't know what to drop...\n";
		return;
	}

	Item* item = GetItem(args[1]);

	if (item == nullptr) {
		cout << "I don't have that";
		return;
	}

	playerCurrentRoom->AddItem(item);
	RemoveItem(item);
	cout << item->Name() << " dropped";
}

void Player::Examine(vector<string> args)
{
	if (args.size() < 2) {
		cout << "I don't know what to examine...\n";
		return;
	}

	Item* item = GetItem(args[1]);

	if (item == nullptr) {

		item = playerCurrentRoom->GetItem(args[1]);
		if (item == nullptr) {
			cout << "I don't have that";
			return;
		}
	}

	cout << item->Description() << "\n";
	Container* bag = dynamic_cast<Container*>(item);
	if (bag != nullptr && bag->HasItems()) {
		bag->ReadItems();
	}
}

void Player::Store(vector<string> args)
{
	if (args.size() != 4) {
		cout << "I don't know what to store...";
		return;
	}

	if (args[2] != "in") {
		cout << "I don't know how to do that";
		return;
	}

	Item* itemToStore = GetItem(args[1]);

	if (itemToStore == nullptr) {
		cout << "I don't have that";
		return;
	}

	if (!itemToStore->IsStoreable()) {
		cout << "It's too big to store it here";
		return;
	}

	Item* itemContainer = GetItem(args[3]);

	if (itemContainer == nullptr) {
		cout << "I don't have that";
		return;
	}

	Container* container = dynamic_cast<Container*>(itemContainer);
	if (container == nullptr) {
		cout << "I can't store anything here";
		return;
	}

	container->AddItem(itemToStore);
	RemoveItem(itemToStore);
	cout << itemToStore->Name() << " stored in " << container->Name();
}

void Player::Use(vector<string> args)
{
	if (args.size() < 2 || args.size() > 4) {
		cout << "I don't what to use...";
		return;
	}

	if (args.size() == 2) {

	}
	else if (args.size() == 4) {
		if (args[2] != "in") {
			cout << "I don't what to use...";
			return;
		}

		Item* itemComputer = playerCurrentRoom->GetItem(args[3]);
		if (itemComputer == nullptr) {
			cout << "I can't find where to use it";
			return;
		}

		Container* computer = dynamic_cast<Container*>(itemComputer);
		if (computer == nullptr) {
			cout << "I can't use this here";
			return;
		}

		if (ToLower(computer->Name()) != "computer") {
			cout << "I can't use this here";
			return;
		}

		Item* itemUsb = GetItem(args[1]);
		if (itemUsb == nullptr) {
			cout << "I don't have that";
			return;
		}

		Usb* usb = dynamic_cast<Usb*>(itemUsb);
		if (usb == nullptr) {
			cout << "I can't use that here";
			return;
		}

		computer->AddItem(itemUsb);
		RemoveItem(itemUsb);
		cout << "You insert the usb in the computer and a code shows in the screen: " << usb->Code();
		computer->SetDescription("Computer with an usb port. It shows the code " + usb->Code() + " in the screen");
	}
	else {
		cout << "I don't what to use...";
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
	else if (args[0] == "look") Look();
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
	else if (args[0] == "drop") Drop(args);
	else if (args[0] == "examine") Examine(args);
	else if (args[0] == "store") Store(args);
	else if (args[0] == "use") Use(args);
	else cout << "\nI can't do that";
}

void Player::ReadStatistics()
{
	cout << "Player stats:\n";
	cout << "Hunger: " << playerCurrentHunger << " / " << playerMaxHunger << "\n";
	cout << "Thirst: " << playerCurrentThirst << " / " << playerMaxThirst << "\n";
	cout << "\n";
}

Item* Player::GetItem(string name)
{
	for (size_t i = 0; i < playerInventory.size(); i++)
	{
		if (ToLower(playerInventory[i]->Name()) == name) return playerInventory[i];
	}

	return nullptr;
}
