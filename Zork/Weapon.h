#pragma once

#include "Item.h"

class Weapon : public Item
{
private:
	int weaponDamage;		//The damage that the weapon deals
	int weaponMaxAmmo;		//The maximum number of ammo that the weapon can hold
	int weaponCurrentAmmo;	//The current number of ammo that is left in the weapon

public:
	Weapon(string name, string description, bool isPickeable, bool isStoreable, int damage, int maxAmmo, int currentAmmo);	//Constructor of the weapon class that sets an initial current ammo amount
	Weapon(string name, string description, bool isPickeable, bool isStoreable, int damage, int maxAmmo);					//Constructor of the weapon class where the current ammo is set to the max ammo
	
	int Damage();		//Returns the damage that the weapon deals
	int MaxAmmo();		//Returns the maximum ammo that the weapon can hold
	int CurrentAmmo();	//Returns the current ammo that the weapon has
	bool Shoot();		//Shoots the weapon
};