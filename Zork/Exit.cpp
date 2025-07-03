#include "Room.h"
#include "Exit.h"


Exit::Exit(string name, string direction1, string direction2, Room* room1, Room* room2, bool needCode, string code)
{
	exitName = name;
	exitDirection1 = direction1;
	exitDirection2 = direction2;
	exitRoom1 = room1;
	exitRoom2 = room2;
	exitNeedCode = needCode;
	exitCode = code;
}

string Exit::Name()
{
	return exitName;
}

string Exit::Direction1()
{
	return exitDirection1;
}

string Exit::Direction2()
{
	return exitDirection2;
}

Room* Exit::Room1()
{
	return exitRoom1;
}

Room* Exit::Room2()
{
	return exitRoom2;
}

bool Exit::NeedCode()
{
	return exitNeedCode;
}

string Exit::Code()
{
	return exitCode;
}
