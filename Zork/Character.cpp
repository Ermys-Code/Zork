#include "Character.h"

Character::Character(string name, string description)
{
	characterName = name;
	characterDescription = description;
}

string Character::Name()
{
	return characterName;
}

string Character::Description()
{
	return characterDescription;
}
