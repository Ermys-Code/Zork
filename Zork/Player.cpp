#include "Player.h"

int Player::Go(vector<string> args)
{
	string direction = args[1];

	Exit* exit = playerCurrentRoom->HasExitOfDirection(direction);

	if (exit == nullptr) {
		cout << "I can't go this way";
		return 0;
	}

	if (exit->NeedCode()) {
		cout << "Insert the code: ";
		string code;
		getline(cin, code);
		if (code != exit->Code()) {
			cout << "Incorrect code\n";
			return 0;
		}
	}

	Room* room = exit->GetRoomOnDirection(direction);

	if(room != nullptr){
		playerCurrentRoom = room;
		cout << "\n\n";
		Look();
		return 1;
	}
	else
	{
		cout << "I can't go that way.";
		return 0;
	}
}

void Player::Help()
{
	cout << "\n";
	cout << "Help: Shows all commands\n";
	cout << "Inventory: Shows all the items on your inventory\n";
	cout << "Stats: Shows all the stats of the player\n";
	cout << "Go <direction>: Moves to the specified direction. You can skip the word 'Go'\n";
	cout << "Look: Describes the room where you currently are\n";
	cout << "Take <item>: Takes the item from the location and stores it in your inventory\n";
	cout << "Take <item> from <container>: Takes the item from the container and stores it in your inventory\n";
	cout << "Drop <item>: Drops the item from your inventory to the current location\n";
	cout << "Examine <item>: Examine the specified item\n";
	cout << "Examine <direction>: Examine the specified direction if it exist\n";
	cout << "Store <item> in <container>: Stores the item in the container\n";
	cout << "Use <item>: Uses the item\n";
	cout << "Use <item> on <item>: Uses the first item on the second item\n";
	cout << "Shoot <target>: Shoot at the target if you have a weapon in the inventory\n";
	cout << "Sleep: Go back to sleep on your cryostasis capsule\n";
}

void Player::Stats()
{
	ReadStatistics();
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
	if (playerCurrentRoom->HasCharacters()) {
		cout << "Characters:\n";
		playerCurrentRoom->ReadCharacters();
	}
	if (playerCurrentRoom->HasExits()) {
		cout << "Exits:\n";
		playerCurrentRoom->ReadExits();
	}
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
			Character* character = playerCurrentRoom->GetCharacter(args[1]);
			if (character == nullptr) {
				Exit* exit = playerCurrentRoom->HasExitOfDirection(args[1]);
				if (exit == nullptr) {
					cout << "I don't have that";
					return;
				}

				cout << "There is a sign, it reads: " << exit->GetRoomOnDirection(args[1])->Name();
				return;
			}

			cout << character->Description() << "\n";
			return;
		}
	}

	cout << item->Description() << "\n";
	Container* bag = dynamic_cast<Container*>(item);
	if (bag != nullptr && bag->HasItems()) {
		bag->ReadItems();
	}

	Weapon* weapon = dynamic_cast<Weapon*>(item);
	if (weapon != nullptr) {
		cout << "Ammo: " << weapon->CurrentAmmo() << " / " << weapon->MaxAmmo();
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
		cout << "I don't know what to use...";
		return;
	}

	if (args.size() == 2) {
		Item* item = GetItem(args[1]);

		if (item == nullptr) {

			if (args[1] == "panel") {
				item = playerCurrentRoom->GetItem(args[1]);
			}
			if (item == nullptr) {
				cout << "I don't have that";
				return;
			}
		}

		Consumable* consumable = dynamic_cast<Consumable*>(item);
		if (consumable != nullptr) {
			if (consumable->Effect() == Hunger) {
				playerCurrentHunger += consumable->Strength();
				if (playerCurrentHunger > playerMaxHunger) playerCurrentHunger = playerMaxHunger;
			}
			else if (consumable->Effect() == Thirst) {
				playerCurrentThirst += consumable->Strength();
				if (playerCurrentThirst > playerMaxThirst) playerCurrentThirst = playerMaxThirst;
			}

			cout << consumable->Name() << " has been consumed\n";
			RemoveItem(consumable);
			return;
		}

		ControlPanel* panel = dynamic_cast<ControlPanel*>(item);
		if (panel != nullptr) {
			if (!panel->IsActive()) {
				panel->ActivatePanel();
				playerCanSleep = true;
				cout << "The cryostasis capsule has been restored\n";
				panel->GetRoom()->AddCharacter(panel->GetEnemy());
				cout << "You hear animal like noises\n";
			}
			else {
				cout << "The cryostasis capsule is already restarted.";
			}
			return;
		}

		cout << "I can't use that";
		return;
	}
	else if (args.size() == 4) {
		if (args[2] != "on") {
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

void Player::Shoot(vector<string> args)
{
	if (args.size() != 2) {
		cout << "I don't know who is that";
		return;
	}

	Item* itemPistol = GetItem("pistol");

	if (itemPistol == nullptr) {
		cout << "I don't have a weapon";
		return;
	}

	Character* characterEnemy = playerCurrentRoom->GetCharacter(args[1]);
	if (characterEnemy == nullptr) {
		cout << "I can't see anyone to shoot...";
		return;
	}

	Enemy* enemy = dynamic_cast<Enemy*>(characterEnemy);
	if (enemy == nullptr) {
		cout << "I can't do that...";
		return;
	}

	Weapon* pistol = dynamic_cast<Weapon*>(itemPistol);
	if (pistol->Shoot()) {
		cout << "You shoot\n";
		enemy->GetDamage(pistol->Damage());
		if (enemy->CurrentHealth() == 0) {
			playerCurrentRoom->RemoveCharacter(characterEnemy);
			cout << enemy->Name() << " has been killed\n";
		}
		else {
			cout << enemy->Name() << " is still alive\n";
		}
	}
	else {
		cout << "You're out of ammo\n";
	}
}

int Player::Sleep()
{
	if (ToLower(playerCurrentRoom->Name()) != "cryostasis chamber") {
		cout << "There are not cryostasis chambers here.";
		return 0;
	}

	if (!playerCanSleep) {
		cout << "My cryostasis capsule still needs to be restarted";
		return 0;
	}

	if (playerCurrentRoom->HasCharacters()) {
		cout << "The Alien is in the middle";
		return 0;
	}

	cout << "You go back to your sleep";
	return 2;
}

Player::Player(string name, string description, int maxHunger, int currentHunger, int maxThirst, int currentThirst, Room* currentRoom) : Character(name, description)
{
	playerMaxHunger = maxHunger;
	playerCurrentHunger = currentHunger;
	playerMaxThirst = maxThirst;
	playerCurrentThirst = currentThirst;
	playerCurrentRoom = currentRoom;
	playerCanSleep = false;
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

int Player::ExecuteCommand(vector<string> args)
{
	if (args[0] == "help") {
		Help();
		return 0;
	}
	else if (args[0] == "inventory") {
		Inventory();
		return 0;
	}
	else if (args[0] == "stats") {
		Stats();
		return 0;
	}
	else if (args[0] == "look") {
		Look();
		return 0;
	}
	else if (args[0] == "go") {
		return Go(args);
	}
	else if (args[0] == "north") {
		args.push_back("north");
		return Go(args);
	}
	else if (args[0] == "south") {
		args.push_back("south");
		return Go(args);
	}
	else if (args[0] == "east") {
		args.push_back("east");
		return Go(args);
	}
	else if (args[0] == "west") {
		args.push_back("west");
		return Go(args);
	}
	else if (args[0] == "take") {
		Take(args);
		return 0;
	}
	else if (args[0] == "drop") {
		Drop(args);
		return 0;
	}
	else if (args[0] == "examine") {
		Examine(args);
		return 0;
	}
	else if (args[0] == "store") {
		Store(args);
		return 0;
	}
	else if (args[0] == "use") {
		Use(args);
		return 0;
	}
	else if (args[0] == "shoot") {
		Shoot(args);
		return 0;
	}
	else if (args[0] == "sleep") {
		return Sleep();
	}
	else {
		cout << "\nI can't do that";
		return 0;
	}
}

void Player::ReadStatistics()
{
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

void Player::UpdateStats()
{
	playerCurrentHunger--;
	playerCurrentThirst--;

	if (playerCurrentHunger == 5) cout << "You're starting to get hungry.";
	if (playerCurrentThirst == 5) cout << "You're starting to get thirsty.";

	if (playerCurrentHunger == 2) cout << "You're really hungry.";
	if (playerCurrentThirst == 2) cout << "You're really thirsty.";

	if (playerCurrentHunger < 0) playerCurrentHunger = 0;
	if (playerCurrentThirst < 0) playerCurrentThirst = 0;

}
