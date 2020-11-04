//
// Created by btnt51 on 11/4/2020.
//

#ifndef INC_9SEM_PARKING_H
#define INC_9SEM_PARKING_H

#include <iostream>
#include <string>
#include "prototypes.h"

class CParking
{
public:

private:
    class CAuto
    {
    public:
        CAuto()
        {
            Number= GeneratingNumber();
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
        void CountintExiting(){ this->CountExiting++;}
    private:
       std::string Number;
       int CountExiting;
    };

};


#endif //INC_9SEM_PARKING_H
