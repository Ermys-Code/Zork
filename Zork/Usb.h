#pragma once

#include "Item.h"

class Usb : public Item
{
private:
	string usbCode;
public:
	Usb(string name, string description, bool isPickeable, bool isStoreable, string code);
	string Code();
};

