#include "Character.h"

Character::Character(string name, string description)
{
	characterName = name;
	characterDescription = description;
}

Character::~Character()
{
}

string Character::Name()
{
	return characterName;
}

string Character::Description()
{
	return characterDescription;
}
