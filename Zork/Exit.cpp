#include "Room.h"
#include "Exit.h"


Exit::Exit(string direction1, string direction2, Room* room1, Room* room2, string code)
{
	exitDirection1 = direction1;
	exitDirection2 = direction2;
	exitRoom1 = room1;
	exitRoom2 = room2;
	exitNeedCode = true;
	exitCode = code;
}

Exit::Exit(string direction1, string direction2, Room* room1, Room* room2)
{
	exitDirection1 = direction1;
	exitDirection2 = direction2;
	exitRoom1 = room1;
	exitRoom2 = room2;
	exitNeedCode = false;
	exitCode = "";
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

bool Exit::HasDirection(string direction, Room* room)
{
	if (exitRoom1 == room) return exitDirection2 == direction;
	else return exitDirection1 == direction;
}

Room* Exit::GetRoomOnDirection(string direction)
{
	if (direction == exitDirection1) return exitRoom1;
	else return exitRoom2;
}

int Exit::GetDirectionFromRoom(Room* room)
{
	if (room == exitRoom1) {
		if (exitDirection2 == "north") return 1;
		if (exitDirection2 == "south") return 2;
		if (exitDirection2 == "east") return 3;
		if (exitDirection2 == "west") return 4;
	}
	else if (room == exitRoom2) {
		if (exitDirection1 == "north") return 1;
		if (exitDirection1 == "south") return 2;
		if (exitDirection1 == "east") return 3;
		if (exitDirection1 == "west") return 4;
	}
	else return 0;
}
