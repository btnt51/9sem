//
// Created by btnt51 on 11/4/2020.
//

#include <iostream>
#include <string>
#include <ctime>


using namespace std;

string GeneratingNumber(int a)
{
    srand(time(nullptr)*a);
    string alpabet = "ABCEHMKOPTYX";
    string result;
    result += alpabet[rand() % 12 + 0];
    for(int i =0; i < 3;i++)
        result+= to_string(rand() % 9 +0);
    for (int i = 0; i < 2; ++i)
        result += alpabet[rand() % 12 + 0];
    return result;
}

