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
        int ChooseArrivalDeparture()
        {
            char a = ' ';
            std::cout << "To place the car in the Parking lot, press 1/nTo pick up a car from the Parking lot, press 2"<< std::endl;
            std::cin >> a;
            switch (a) {
                case '1': {
                    Arrival();
                    break;
                }
                case '2': {
                    Departure();
                    break;
                }
                default: {
                    std::cout <<"You entered an incorrect value. Enter again."<< std::endl;
                    ChooseArrivalDeparture();
                    break;
                }
            }

        }
        int Arrival()
        {

        }
        int Departure()
        {

        }
        void CountingExiting(){ this->CountExiting++;}
    private:
       std::string Number;
       int CountExiting;
    };

};


#endif //INC_9SEM_PARKING_H
