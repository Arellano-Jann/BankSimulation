#include "PQueue.h"
template<typename T>
bool PQueue<T>::isEmpty() const{
    return numItems == 0; 
}

#include <iostream>
template<typename T>
bool PQueue<T>::enqueue(const T& newEntry){
    bool funcWork = false;
    if (numItems < CAPACITY && numItems != 0){
        for (int i = back; i >= 0; i--){
            if (queueArray[i] < newEntry){
                numItems++;
                back = (back+1)%CAPACITY;
                queueArray[i+1] = newEntry;
                funcWork = true;
                return funcWork;
            }else{
                queueArray[i+1] = queueArray[i];
            }
        }
    }else if (isEmpty()){
        queueArray[back] = newEntry;
        funcWork = true;
        numItems++;
    }

    return funcWork;
}

template<typename T>
bool PQueue<T>::dequeue(){
    bool funcWork = false;
    if(isEmpty() == false){
        front = (front+1) % CAPACITY;
        numItems--;
        funcWork = true;
    }
    return funcWork;
}

template<typename T>
T PQueue<T>::peekFront() const{
    return queueArray[front];
}