//
// Created by btnt51 on 11/4/2020.
//
//#define OwnList
#define stllist
#include "Parking.h"

CParking::CParking(int x)
{
   if(x == 1)
   {
       int Cars = rand() % 10 + 2;
       for(int i = 0; i < Cars; i++)
           this->Arrival();
   }

}

CParking::~CParking()
{
    LCars.clear();
}

void CParking::Arrival()
{
    CAuto newCar;
    LCars.push_back(newCar);
    std::cout << newCar.getInfoArrival() << " at " << LCars.size() << std::endl;
    newCar.~CAuto();
}

void CParking::Departure(std::string Number)
{
#ifdef OwnList
    for(int i = 0; i < LCars.size();i++)
    {
        if(LCars[i].getNumber() == Number)
        {
            std::cout<< LCars[i].getInfoDeparture() << std::endl;
            LCars.removeAt(i);

        }
        else
            LCars[i].CountingExiting();
    }
#endif
#ifdef stllist
    int i = 0;
    for(auto iter = LCars.begin(); iter != LCars.end();iter++)
    {
        if(iter->getNumber() == Number)
        {
            std::cout<< iter->getInfoDeparture() << std::endl;
            removeAt(i);
        }
        else
        {
            iter->CountingExiting();
            i++;
        }

    }
    #endif
}

void CParking::Display()
{
#ifdef OwnList
    for(int i = 0; i < LCars.size(); i++)
        std::cout << "Parking lot#" << i+1 << " Number of car is " <<
                  LCars[i].getNumber() << std::endl;
#endif
#ifdef stllist
    int i =0;
    auto iterator = LCars.begin();
    while(i <= LCars.size())
    {
        std::cout << "Parking lot#" << i+1 << " Number of car is " <<
            iterator->getNumber() << std::endl;
        iterator++;
        i++;
    }
#endif
}

#ifdef stllist
void CParking::removeAt(int k)
{
    int i=0;
    auto iterator= LCars.begin();
    while(i <= k)
    {
        if(i==k)
        {
            LCars.remove(*iterator);
        }
        iterator++;
        i++;
    }
}
#endif



