//
// Created by btnt51 on 27.11.2020.
//

#ifndef INC_9SEM_MENU_H
#define INC_9SEM_MENU_H
#include "Parking.h"

class CMenu {
public:
    CMenu();//конструктор по умолчанию
    ~CMenu();//дестркутор по умолчанию
    void Menu();//основная функция

private:
    CParking Park;//создаём объект парковки
};


#endif //INC_9SEM_MENU_H
