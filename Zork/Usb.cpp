#include "Usb.h"

Usb::Usb(string name, string description, bool isPickeable, bool isStoreable, string code) : Item(name, description, isPickeable, isStoreable)
{
	usbCode = code;
}

string Usb::Code()
{
	return usbCode;
}
