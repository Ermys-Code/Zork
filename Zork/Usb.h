#pragma once

#include "Item.h"

class Usb : public Item
{
private:
	string usbCode;	//The code that the usb contains to open the door
	
public:
	Usb(string name, string description, bool isPickeable, bool isStoreable, string code);	//Constructor of the Usb class

	string Code(); //Returs the code that contains the usb
};

