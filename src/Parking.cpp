//
// Created by btnt51 on 11/4/2020.
//

#include "Parking.h"

CParking::CParking(int x)
{
    switch (x)
    {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}

CParking::~CParking()
{
    LCars.clear();
}

void CParking::ChooseArrivalDeparture(const std::string& Command)
{

    std::cout << "To place the car in the Parking lot, press 1/n"
                 "To pick up a car from the Parking lot, press 2"<< std::endl;
    std::string Arrival("arrival");
    int Size = Command.length();
    if(Size == 7)
    {
        
    }
}

void CParking::Arrival()
{
    CAuto newCar;
    LCars.push_back(newCar);
    std::cout << newCar.getInfoArrival() << " at " << LCars.Length() << std::endl;
    newCar.~CAuto();
}

void CParking::Departure(std::string Number)
{
    for(int i = 0; i < LCars.Length();i++)
    {
        if(LCars[i].getNumber() == Number)
        {
            std::cout<< LCars[i].getInfoDeparture() << std::endl;
            LCars.removeAt(i);
        }
        else
            LCars[i].CountingExiting();
    }
}

void CParking::Display()
{
    for(int i = 0; i < LCars.Length(); i++)
        std::cout << "Parking lot#" << i+1 << " Number of car is " <<
        LCars[i].getNumber() << std::endl;
}
