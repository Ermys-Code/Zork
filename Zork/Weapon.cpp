#include "Weapon.h"

Weapon::Weapon(string name, string description, bool isPickeable, bool isStoreable, int damage, int maxAmmo, int currentAmmo) : Item(name, description, isPickeable, isStoreable)
{
	weaponDamage = damage;
	weaponMaxAmmo = maxAmmo;
	weaponCurrentAmmo = currentAmmo;
}

Weapon::Weapon(string name, string description, bool isPickeable, bool isStoreable, int damage, int maxAmmo) : Item(name, description, isPickeable, isStoreable)
{
	weaponDamage = damage;
	weaponMaxAmmo = maxAmmo;
	weaponCurrentAmmo = maxAmmo;
}

int Weapon::Damage()
{
	return weaponDamage;
}

int Weapon::MaxAmmo()
{
	return weaponMaxAmmo;
}

int Weapon::CurrentAmmo()
{
	return weaponCurrentAmmo;
}

bool Weapon::Shoot()
{
	if (weaponCurrentAmmo == 0) return false;

	weaponCurrentAmmo--;
	return true;
}
