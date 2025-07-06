#include <iostream>
#include "Scenario.h"

int main()
{
    Scenario scenario;

    string command;
    vector<string> args;
    int result;
    bool win;

    cout << "WELCOME TO FIX YOUR CRYOCAPSULE" << "\n";
    cout << "-------------------------------" << "\n";
    cout << "Restart your cryostasis capsule and go back to your sleep and dont starve in the process.";
    cout << "\n\n\n\n\n";
    scenario.DescribePlayerRoom();
    cout << "\n";

    while (true)
    {
        command = scenario.AskForCommand();
        if (command == "") continue;
        args = scenario.ProcessCommand(command);
        result = scenario.GetPlayer()->ExecuteCommand(args);
        if (result == 1) {
            scenario.GetPlayer()->UpdateStats();
            if (scenario.GetPlayer()->CurrentHunger() == 0 || scenario.GetPlayer()->CurrentThirst() == 0) {
                cout << "You don't have more energy left in yout body\n";
                win = false;
                break;
            }
        }
        else if(result == 2){
            win = true;
            break;
        }

    
        cout << "\n\n\n";
    }

    if (win) {
        cout << "\n\n\n\n\nYOU WIN\n";
    }
    else {
        cout << "\n\n\n\n\nYOU LOSE\n";
    }
    cout << "Thanks for playing!\n\n\n";
    cout << "Made by: Raul Rodriguez Trotonda\n";
    cout << "Github: Ermys-Code\n";
    
    return 0;
}