#pragma once

#include <string>

using namespace std;

class Character
{
private:
	string characterName;			//The name of the character
	string characterDescription;	//The description of the character

public:
	Character(string name, string description);	//The constructor of the character class

	string Name();			//Returns the name of the character
	string Description();	//Returns the description of the character
};

