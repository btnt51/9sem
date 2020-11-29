//
// Created by btnt51 on 11/4/2020.
//

#ifndef INC_9SEM_PARKING_H
#define INC_9SEM_PARKING_H

#include <iostream>
#include <string>
#include <list>
#include "prototypes.h"
#include "COurOwmList.h"
//#include "CAuto.h"

class CParking
{
public:
    CParking();                         //констркутор по-умолчанию
    ~CParking();                        //дестркутор по-умолчанию
    void Arrival();                     //функция приезда машины
    void Departure(std::string Number); //функция выезда машины с праковки
    void Display();                     //функция вывода всех машин на парковке
    bool CheckNums(std::string Number);                   //проверка на наличие номера в базе парковке

private:
    class CAuto
    {
    public:
        CAuto() //констркутор по умолчанию
        {
            Number = GeneratingNumber(rand()*rand()); //генерация уникального номера для машины
            CountExiting = 0;                           //обнуление счётчика вызовов машины
        }

        ~CAuto() //деструктор по умолчанию
        {
            Number.clear();     //очистка номера
            CountExiting = 0;   //обнуление счётчика вызовов машины
        }
        std::string getInfoDeparture()                  //функция возврата шаблона выезда машины
        {
            return "\n"
                   "Car with number " + this->Number + " leaving the parking lot\nCar with number: " + this->Number +
                   "deleted " + std::to_string(CountExiting) + " -times";
        }
        std::string getInfoArrival()                    //функция возврата шаблона заезда машины
        {
            return "Car number " + this->Number + " arrived at the parking lot";
        }
        std::string getNumber(){ return Number; }       //геттер получения номера машины
        void CountingExiting(){ this->CountExiting++;}  //функция увелечение выезда машина с парковки

    private:
        std::string Number; //Номер машины
        int CountExiting;   //кол-во выезда машины с парковки чтобы выехала другая машина
    };


#ifdef OwnList
    COwnList<CAuto> LCars; //свой собственный контейнер
#endif //OwnList
#ifdef stllist
    std::list<CAuto> LCars; //stl констркутор лист
#endif //stllist
    std::list<std::string> LNums;
};


#endif //INC_9SEM_PARKING_H
