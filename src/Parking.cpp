//
// Created by btnt51 on 11/4/2020.
//
#define OwnList
//#define stllist
#include "Parking.h"

CParking::CParking()
{

}

CParking::~CParking()
{
    LCars.clear(); //очистка контейнера
}

void CParking::Arrival()
{
    CAuto newCar;               //создание объекта машины
    LCars.push_back(newCar);    //добавление машины в контейнер
    LNums.push_back(newCar.getNumber());
    std::cout << newCar.getInfoArrival() << " at " << LCars.size() << std::endl; // вывод информации о новой машине
    newCar.~CAuto();            //вызов деструктора навсякий случай
}

void CParking::Departure(std::string Number)
{
#ifdef OwnList
    if(CheckNums(Number))
    {
        for(int i = 0; i < LCars.size();i++) //цикл
        {
            if(LCars[i].getNumber() == Number) //сравнение номера машины и номера который нужно удалить
            {
                std::cout<< LCars[i].getInfoDeparture() << std::endl; //если совпали то выводим информацию о машине
                LCars.removeAt(i);  //удаляем машины из контейнера
            }
            else
                LCars[i].CountingExiting(); //если не совпали номера то увеличиваем на 1 кол-во выезда машины
        }
    }
    else
    {
        std::cout << "There is no car with this number " << Number << std::endl;
    }
#endif
#ifdef stllist // всё тоже самое только через стл лист
    if(CheckNums(Number)) {
        for (auto iter = LCars.begin(); iter != LCars.end(); iter++)
        {
            if (iter->getNumber() == Number)
            {
                std::cout << iter->getInfoDeparture() << std::endl;
                iter = LCars.erase(iter);
            } else
            {
                iter->CountingExiting();
            }
        }
    }
    else
    {
        std::cout << "There is no car with this number " << Number << std::endl;
    }
#endif
}

void CParking::Display()
{ //простая функция вывожа машин на парковке
#ifdef OwnList
    for(int i = 0; i < LCars.size(); i++)
        std::cout << "Parking lot#" << i+1 << " Number of car is " <<
                  LCars[i].getNumber() << std::endl;
#endif
#ifdef stllist
    int i = 0;
    std::for_each(LCars.begin(), LCars.end(), [&i](auto Element){
        std::cout << "Parking lot#" << ++i << " Number of car is " <<
                             Element.getNumber() << std::endl;
    });
    i=0;
#endif
}

bool CParking::CheckNums(std::string Number)
{
    for(auto iter = LNums.begin(); iter != LNums.end();iter++)
    {
        if (iter->data() == Number)
        {
            iter = LNums.erase(iter);
            return true;
        }
    }
    return false;
}

