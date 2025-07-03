#include <iostream>
#include "Scenario.h"

int main()
{
    Scenario scenario;

    cout << scenario.GetRooms()[0]->Name();
    
    return 0;
}