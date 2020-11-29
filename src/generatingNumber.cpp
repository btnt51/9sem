//
// Created by btnt51 on 11/4/2020.
//

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string GeneratingNumber(int a)//функции принимает случайное число и используется его в качестве соли
{                             //и генерирует рандомайзер
    srand(time(nullptr)*a); //генератор рандомайзера
    string alpabet = "ABCEHMKOPTYX"; //список доступных букв
    string result;
    result += alpabet[rand() % 12 + 0];// заносим первую случайную букву
    for(int i =0; i < 3;i++)
        result+= to_string(rand() % 9 + 0);//заносим три случайных цифры
    for (int i = 0; i < 2; ++i)
        result += alpabet[rand() % 12 + 0];//заносим две случайные буквы
    return result;
}

