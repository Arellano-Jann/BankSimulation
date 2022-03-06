#include "PQueue.h"

template<typename T>
bool PQueue<T>::isEmpty() const{
    return numItems == 0; 
}

#include <iostream>
template<typename T>
bool PQueue<T>::enqueue(const T& newEntry){
    bool funcWork = false;
    if(numItems < CAPACITY && numItems > 0){
        std::cout<< "if capacity" <<std::endl;
        for(int i = back; i < 1; i--){
            if(queueArray[i]< newEntry){ //if the entry has higher priority than new entry
                back = (back+1)%CAPACITY;
                queueArray[i+1] = queueArray[i];
                queueArray[i] = newEntry;
            }else{
                queueArray[i+1] = newEntry;
            }
            // back = (back++) % CAPACITY;
            // queueArray[back] = newEntry;
             //numItems++;

            
            //     queueArray[(index-1+CAPACITY)%CAPACITY] = queueArray[i];
            //     //std::cout<< index <<std::endl;
            //     index++;
            //     if(!frontMove){
            //         std::cout<<"1 front" <<std::endl;
            //         front = (front-1+CAPACITY)%CAPACITY;
            //         frontMove = true;
            //     }
            // }else{
            //     queueArray[(index-1+CAPACITY)%CAPACITY] = newEntry;
            // }
            funcWork = true;
        }
    }else if(numItems == 0){
        std::cout << "first item" <<std::endl;
        queueArray[front] = newEntry;
        back++;
    }
    std::cout<<front<<std::endl;
    numItems++;
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
    std::cout<<front<<std::endl;
    return funcWork;
}

template<typename T>
T PQueue<T>::peekFront() const{
    return queueArray[front];
}