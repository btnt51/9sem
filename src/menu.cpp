//
// Created by btnt51 on 27.11.2020.
//
#include <cstring>
#include "menu.h"
#include "inputData.h"


CMenu::CMenu()
{
    std::cout << "Enter plz how u want to make a parking lot" << std::endl;
    std::cout << "By yourself or in automatic mode" << std::endl;
    int choice = 0;
    std::cout << "Enter 0 if u want to make it by your self" << std::endl;
    std::cout << "Or enter 1 if u want to do it in automatic mode" << std::endl;
    choice = inputData(choice,"Enter plz 0 if u want to do by yourself or 1 to do it in auto mode");
    while(1 < choice || choice < 0)
    {
       choice = inputData(choice,"Enter plz 0 if u want to do by yourself or 1 to do it in auto mode");
    }
    Park = new CParking(choice);
}

CMenu::~CMenu()
{
    delete Park;
}

void CMenu::Menu()
{
    int CheckVar = 0;
    while(true) {
        Park->Display();
        std::string Command;
        if(CheckVar == 1)
        {
            std::cout << "Enter plz arrival for adding car to parking lot" << std::endl;
            std::cout << "Enter departure for executing car from parking lot" << std::endl;
            std::cout << "Enter exit for exiting from program" << std::endl;
        }
        CheckVar = 1;
        std::getline(std::cin, Command);
        int Size = Command.length();
        if (Size == 16)
        {
            std::string delimiter = " ";
            int pos = Command.find(delimiter);
            std::string LocalCommand;
            LocalCommand = Command.substr(0, pos);
            std::string Number;
            Number = Command.substr(pos + 1, Command.size());
            for (char &c : LocalCommand) c = toupper(c);
            if (strcmp(LocalCommand.c_str(), "DEPARTURE") == 0)
                Park->Departure(Number);
        }
        else
        {
            for (char &c : Command) c = toupper(c);
            if (strcmp(Command.c_str(), "EXIT") == 0)
            {
                break;
            }
            else if (strcmp(Command.c_str(), "ARRIVAL") == 0 || strcmp(Command.c_str(), "ARIVAL") == 0)
            {
                Park->Arrival();
            }
        }
    }
}
