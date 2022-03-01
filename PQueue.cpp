#include "PQueue.h"

template<typename T>
bool PQueue<T>::isEmpty() const{
    return count == 0; 
}

template<typename T>
bool PQueue<T>::enqueque(const T& newEntry){
    bool funcWork = false;
    if(numItems < CAPACITY){
        back++;
        queueArray[back];
        numItems++;
        funcWork = true;
    }
    return funcWork;
}

template<typename T>
bool PQueue<T>::dequeue(){
    bool funcWork = false;
    if(isEmpty == false){
        front++;
        numItems--;
        funcWork = true;
    }
    return funcWork;
}

template<typename T>
T PQueue<T>::peekFront() const{
    return queueArray[front];
}