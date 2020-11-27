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
    Park->Display();
    while(true)
    {
        std::string Command = " ";
        std::cout << "Enter plz arrival for adding car to parking lot" << std::endl;
        std::cout << "Enter departure for executing car from parking lot" << std::endl;
        std::cout << "Enter exit for exiting from program" << std::endl;
        Park->Display();
        std::cin >> Command;
        for(char & c : Command) c = toupper(c);              //Переписать тут разделение на больше и меньше
        // 16 символов чтобы нормально работать с этой залупой!!!!!
        if(strcmp(Command.c_str(),"EXIT") == 0)
        {
            break;
        }
        else if(strcmp(Command.c_str(),"ARRIVAL") == 0 || strcmp(Command.c_str(), "ARIVAL")==0)
        {
            Park->Arrival();
        }
        else if(Command.length() == 15)
        {
            int j = 0;
            std::string CommandAndNumber[2];
            for(int i = 0; i < 16;i++)
            {
                if(i < 9)
                {
                    CommandAndNumber[0][i]=Command[i];
                }
                if(i > 9)
                {
                    CommandAndNumber[1][j] = Command[i];
                    j++;
                }
            }
            if(strcmp(CommandAndNumber[0].c_str(),"DEPARTURE") == 0)
                Park->Departure(CommandAndNumber[1]);
        }
    }
}
