#include "ControlPanel.h"

ControlPanel::ControlPanel(string name, string description, bool isPickeable, bool isStoreable) : Item(name, description, isPickeable, isStoreable)
{
	hasBeenActivated = false;
}

void ControlPanel::ActivatePanel()
{
	hasBeenActivated = true;
}

bool ControlPanel::IsActive()
{
	return hasBeenActivated;
}
