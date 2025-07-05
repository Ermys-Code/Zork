#include <iostream>
#include "Scenario.h"

int main()
{
    Scenario scenario;
    string command;
    vector<string> args;

    cout << "WELCOME TO FIX YOUR CRYOCAPSULE" << "\n";
    cout << "-------------------------------" << "\n";
    cout << "Restart your cryostasis capsule and go back to your sleep and dont starve in the process.";
    cout << "\n\n\n\n\n";
    scenario.DescribePlayerRoom();
    cout << "\n";

    while (true)
    {
        command = scenario.AskForCommand();
        args = scenario.ProcessCommand(command);
        scenario.GetPlayer()->ExecuteCommand(args);
    
        cout << "\n\n\n";
    }

    
    return 0;
}