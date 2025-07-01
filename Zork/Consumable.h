#pragma once

#include "Item.h"

enum EffectType //Enum that represents all types of effects that a consumable can be
{
	Hunger,
	Thirst
};

class Consumable : public Item
{
private:
	EffectType consumableEffect;	//The type of the consumable
	int consumableStrength;			//The number of points that the consumable restores to the correspondent stat of the player

public:
	Consumable(string name, string description, bool isPickeable, bool isStoreable, EffectType effect, int strength);	//Constructor of the consumable class
	
	EffectType Effect();	//Returns the effect type of the consumable
	int Strength();			//Returns the number of points that the consumable restore
};

