#pragma once

#include "Item.h"

class Weapon : public Item
{
private:
	int weaponDamage;
	int weaponMaxAmmo;
	int weaponCurrentAmmo;
public:
	Weapon(string name, string description, bool isPickeable, bool isStoreable, int damage, int maxAmmo, int currentAmmo);
	Weapon(string name, string description, bool isPickeable, bool isStoreable, int damage, int maxAmmo);
	int Damage();
	int MaxAmmo();
	int CurrentAmmo();
};