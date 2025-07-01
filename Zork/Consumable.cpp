#include "Consumable.h"

Consumable::Consumable(string name, string description, bool isPickeable, bool isStoreable, EffectType effect, int strength) : Item(name, description, isPickeable, isStoreable)
{
	consumableEffect = effect;
	consumableStrength = strength;
}

EffectType Consumable::Effect()
{
	return consumableEffect;
}

int Consumable::Strength()
{
	return consumableStrength;
}
