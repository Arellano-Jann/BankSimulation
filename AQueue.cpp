#include "AQueue.h"

template<typename T>
bool AQueue<T>::isEmpty() const{
    return numItems == 0; 
}

template<typename T>
bool AQueue<T>::enqueue(const T& newEntry){
    bool funcWork = false;
    if(numItems < CAPACITY && numItems > 0){
        back = (back + 1) % CAPACITY;
        queueArray[back] = newEntry;
        funcWork = true;
    numItems++;
    } else{
        // queueArray[back] = newEntry;
    }
    // numItems++;
    return funcWork;
}

template<typename T>
bool AQueue<T>::dequeue(){
    bool funcWork = false;
    if(isEmpty() == false){
        front = (front + 1) % CAPACITY;
        numItems--;
        funcWork = true;
    }
    return funcWork;
}

template<typename T>
T AQueue<T>::peekFront() const{
    return queueArray[front];
}