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

template<class T>
void COurOwnQueue<T>::push(T item)
{
    T *Pointer2;
    Pointer2 = this->Pointer;
    try
    {
        this->Pointer = new T[this->Count + 1];
        for(int i = 0; i < Count; i++)
            Pointer[i] = Pointer2;
        Pointer[Count] = item;
        Count++;
        if(Count > 1)
            delete [] Pointer;
    }
    catch (std::bad_alloc e) {
        std::cout << e.what() << std::endl;
        Pointer = Pointer2;
    }
}

template<class T>
T COurOwnQueue<T>::pop()
{
    if (Count == 0)
        return 0;

    // заполнить элемент, который вытягивается из очереди
    T item;

    item = Pointer[0];

    // сформировать новый участок памяти, который на 1 меньше
    try {
        T* Pointer2;


        // попытка выделить пам'ять
        Pointer2 = new T[Count - 1];

        Count--; // уменьшить количество элементов в очереди

        // p=>Pointer2
        for (int i = 0; i < Count; i++)
            Pointer2[i] = Pointer[i + 1]; // копируются все кроме первого элемента

        // освободить участок, на который указывает p
        if (Count > 0)
            delete[] Pointer;

        // перенаправить p на Pointer2
        Pointer = Pointer2;

        // вернуть item
        return item;
    }
    catch (std::bad_alloc e)
    {
        // если память не выделилась, то вернуть 0
        std::cout << e.what() << std::endl;
        return 0;
    }
}