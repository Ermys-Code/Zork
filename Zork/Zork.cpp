#include <iostream>
#include "Scenario.h"

int main()
{
    Scenario scenario;
    string command;

    cout << "WELCOME TO FIX YOUR CRYOCAPSULE" << "\n";
    cout << "-------------------------------" << "\n";
    cout << "Restart your cryostasis capsule and go back to your sleep and dont starve in the process." << "\n\n\n";
    while (true)
    {
        scenario.DescribePlayerRoom();

        command = scenario.AskForCommand();
        cout << command;
    }

    
    return 0;
}