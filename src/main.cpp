#include <iostream>
#include "Parking.h"
int main() {
    std::string Number;
    CParking Park(1);
    Park.Arrival();
    Park.Arrival();
    Park.Arrival();
    Park.Display();
    std::cout << "Enter plz number of car that u want to depart->";
    std::cin >> Number;
    Park.Departure(Number);
    Park.Display();
    Park.Arrival();
    Park.Arrival();
    std::cout << "Enter plz number of car that u want to depart->";
    std::cin >> Number;
    Park.Departure(Number);
    Park.Display();
    return 0;
}
