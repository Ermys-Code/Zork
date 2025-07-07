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
    cout << "Restart your cryostasis capsule and go back to your sleep.";
    cout << "You are hungry and thirsty, find something to eat and drink.";
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
            if (scenario.GetPlayer()->CurrentThirst() == 0) {
                cout << "\n\nYou died of thirst.";
                win = false;
                break;
            }
            else if (scenario.GetPlayer()->CurrentHunger() == 0) {
                cout << "\n\nYou starved to death.";
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

    cout << "\nPress enter to close...";
    getchar();
    
    return 0;
}