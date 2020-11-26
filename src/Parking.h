//
// Created by btnt51 on 11/4/2020.
//

#ifndef INC_9SEM_PARKING_H
#define INC_9SEM_PARKING_H

#include <iostream>
#include <string>
#include "prototypes.h"
#include "COurOwmList.h"

class CParking
{
public:
    CParking(int x);
    ~CParking();
    static void ChooseArrivalDeparture(const std::string& Command);
    void Arrival();
    void Departure(std::string Number);
    void Display();

private:
    class CAuto
    {
    public:
        CAuto()
        {
            Number= GeneratingNumber(rand()*rand());
            CountExiting = 0;
        }
        ~CAuto()
        {
            Number.clear();
            CountExiting = 0;
        }
        std::string getInfoDeparture()
        {
            return "\n"
                   "Car with number " + this->Number + " leaving the parking lot\nCar with number: " + this->Number +
                   "deleted " + std::to_string(CountExiting) + " -times";
        }
        std::string getInfoArrival()
        {
            return "Car number " + this->Number + " arrived at the parking lot";
        }
        std::string getNumber(){ return Number; }
        void CountingExiting(){ this->CountExiting++;}

    private:
       std::string Number;
       int CountExiting;

    };
    COwnList<CAuto> LCars;
};


#endif //INC_9SEM_PARKING_H
