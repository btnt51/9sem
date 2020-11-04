//
// Created by btnt51 on 11/4/2020.
//

#ifndef INC_9SEM_COUROWNQUEUE_H
#define INC_9SEM_COUROWNQUEUE_H


template<class T>
class COurOwnQueue {
public:
    COurOwnQueue();
    COurOwnQueue(const COurOwnQueue&);
    ~COurOwnQueue();
    void push();
    void clear();
    bool IsEmpty();
    int GetN();
    void print(const char* objName);
    T getItem();
    T pop();
    COurOwnQueue& operator=(const COurOwnQueue& obj);


private:
    T *Pointer;
    int Count;
};



#endif //INC_9SEM_COUROWNQUEUE_H
