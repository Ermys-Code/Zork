#pragma once
#include "Item.h"
class ControlPanel : public Item
{
private:
	bool hasBeenActivated;

public:
	ControlPanel(string name, string description, bool isPickeable, bool isStoreable);	//Constructor of the class Bag with no items inside

	void ActivatePanel();
	bool IsActive();
};

