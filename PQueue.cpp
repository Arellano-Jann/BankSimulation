#include "PQueue.h"

template<typename T>
bool PQueue<T>::isEmpty() const{
    return count == 0; 
}

template<typename T>
bool PQueue<T>::enqueque(const T& newEntry){
    int place = 0;
    bool funcWork = false;
    bool frontMove = false;
    int index = front;
    if(numItems < CAPACITY && numItems != 0){
        for(int i = 0; i < CAPACITY; i++){
            if(queueArray[i]> newEntry){ //if the entry has higher priority than neew entry
            // back = (back++) % CAPACITY;
            // queueArray[back] = newEntry;
            // numItems++;
                queueArray[(index-1+CAPACITY)%CAPACITY] = queueArray[i];
                index++;
                if(frontMove!){
                    front = (front-1+CAPACITY)%CAPACITY;
                    frontMove = false;
                }
            }else{
                queueArray[(index-1+CAPACITY)%CAPACITY] = newEntry;
            }
            funcWork = true;
        }
    }else if(numItems == 0){
        queueArray[front];
        numItems++;
    }
    return funcWork;
}

template<typename T>
bool PQueue<T>::dequeue(){
    bool funcWork = false;
    if(isEmpty == false){
        front = (front++) % CAPACITY;
        numItems--;
        funcWork = true;
    }
    return funcWork;
}

template<typename T>
T PQueue<T>::peekFront() const{
    return queueArray[front];
}