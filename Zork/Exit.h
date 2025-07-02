#pragma once

#include <string>
#include "Room.h"

using namespace std;

class Exit
{
private:
	string exitName;		//The name of the exit
	string exitDirection1;	//The direction of the first room that this exit connects
	string exitDirection2;	//The direction of the second room that this exit connects
	Room*  exitRoom1;		//The first room that this exit connects
	Room*  exitRoom2;		//The second room that this exit connects
	bool   exitNeedCode;	//Indicates if the door needs a code to be opened
	string exitCode;		//The code that the door needs to be opened

public:
	Exit(string name, string direction1, string direction2, Room* room1, Room* room2, bool needCode, string code);	//The constructor of the class Exit

	string Name();			//Returns the name of the exit
	string Direction1();	//Returns the direction of the first room tha this exit connects
	string Direction2();	//Returns the direction of the first room tha this exit connects
	Room* Room1();			//Returns the first room that this exit conects
	Room* Room2();			//Returns the second room that this exit conects
	bool NeedCode();		//Returns if the door needs a code to be opened
	string Code();			//Returns the code that the door needs to be opened
};

