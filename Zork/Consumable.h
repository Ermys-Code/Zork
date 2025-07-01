#pragma once

#include "Item.h"

enum EffectType
{
	Hunger,
	Thirst
};

class Consumable : public Item
{
private:
	EffectType consumableEffect;
	int consumableStrength;
public:
	Consumable(string name, string description, bool isPickeable, bool isStoreable, EffectType effect, int strength);
	EffectType Effect();
	int Strength();
};

