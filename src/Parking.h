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
        std::string getInfo()
        {
            return "Car with number: " + this->Number + " is staying on " + PosOnParking +
                   "deleted " + std::to_string(CountExiting) + " -times";
        }
    private:
       std::string Number;
       char PosOnParking;
       int CountExiting;
    };
};


#endif //INC_9SEM_PARKING_H
