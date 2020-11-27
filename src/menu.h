//
// Created by btnt51 on 27.11.2020.
//

#ifndef INC_9SEM_MENU_H
#define INC_9SEM_MENU_H
#include "Parking.h"

class CMenu {
public:
    CMenu();
    ~CMenu();
    //std::string GetNumberFromCommand();
    void Menu();

private:
    CParking *Park;
};


#endif //INC_9SEM_MENU_H
