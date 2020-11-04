//
// Created by btnt51 on 11/4/2020.
//

#ifndef INC_9SEM_PARKING_H
#define INC_9SEM_PARKING_H

#include <iostream>
#include <string>

class CParking
{
public:

private:
    class CAuto
    {
    public:
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
    private:
       std::string Number;
       int CountExiting;
    };
};


#endif //INC_9SEM_PARKING_H
