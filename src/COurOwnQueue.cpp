//
// Created by btnt51 on 11/4/2020.
//

#include "COurOwnQueue.h"
#include <new>
#include <iostream>

template<class T>
COurOwnQueue<T>::COurOwnQueue()
{
    this->Count = 0;
}

template<class T>
COurOwnQueue<T>::COurOwnQueue(const COurOwnQueue &obj)
{
    Count = obj.count;
    try{
        Pointer = new T[Count];
        for (int i = 0; i < Count; ++i) {
            Pointer[i] = obj.Pointer[i];
        }
    }
    catch (std::bad_alloc e)
    {
        std::cout << e.what() << std::endl;
        Count = 0;
    }
}

void push()
{
    
}