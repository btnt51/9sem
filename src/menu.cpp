//
// Created by btnt51 on 27.11.2020.
//
#include <cstring>
#include "menu.h"


CMenu::CMenu()
{

}

CMenu::~CMenu()
{
}

void CMenu::Menu()
{
    int CheckVar = 0; //спец переменная для проверки если первый запуск
    while(true)
    {
        Park.Display(); //вывод инфы о паркове
        std::string Command; //выделение памяти для команды
        if(CheckVar == 1) //проверка на первый запуск если 0 то проход по циклу в пустую
        {
            std::cout << "Enter plz arrival for adding car to parking lot" << std::endl;
            std::cout << "Enter departure for executing car from parking lot" << std::endl;
            std::cout << "Enter exit for exiting from program" << std::endl;
            std::getline(std::cin, Command);   //считывание строки, используется
                                                    // гетлайн из-за особенности работы std::cin
        }
        CheckVar = 1;
        int Size = Command.length(); //вычисление размера строки для корректоной работы
        if (Size == 16) //если размер равен 16 то это точно будет относится к выезду машины
        {
            std::string delimiter = " ";                            //разделитель
            int pos = Command.find(delimiter);                      //получение позиции пробела в команде
            std::string LocalCommand;                               //переменная для проверки на верную команду
            LocalCommand = Command.substr(0, pos);              //запись команды
            std::string Number;                                     //переменная для сохранения номера и
                                                                    // передачи в функцию выезда машин
            Number = Command.substr(pos + 1, Command.size());   //сохранения номера машины
            for (char &c : LocalCommand) c = toupper(c);            //подведение команды в верхний регистр для сравнения
            if (strcmp(LocalCommand.c_str(), "DEPARTURE") == 0)     //сравнение команды и если подходит вызов функции
                Park.Departure(Number);                             //вызов функции выезда машины
        }
        else
        {
            for (char &c : Command) c = toupper(c);                 //подведение команды в верхний регистр для сравнения
            if (strcmp(Command.c_str(), "EXIT") == 0)               //проверка на выход
            {
                break;                                              //выход из программы
            }
            else if (strcmp(Command.c_str(), "ARRIVAL") == 0 || strcmp(Command.c_str(), "ARIVAL") == 0) //сравнение
            {
                Park.Arrival(); //вызов функции приезда машины
            }
        }
    }
}
