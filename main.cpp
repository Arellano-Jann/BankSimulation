// TEAM MEMBERS: Rubi Dionisio and Andy Tan

#include <iostream>
#include <fstream>
#include "AQueue.h"
#include "PQueue.h"
#include "event.h"

//parse file to store data into event objects, then enqueue events into the priority queue
template<typename T>
void load(PQueue<T> &peventPriorityQueue);

template<typename T>
void pArrival(Event aEvent, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue);

template<typename T>
void pDeparture(Event dEvent, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue);

int main(){
    //all the queues
    PQueue<Event> priorityQ;
    AQueue<Event> bankQ;
    int currenttime = 0;
    bool tellAvail = true;
    
    try {
        load(priorityQ);
        while(!priorityQ.isEmpty()){
            Event newEvent= priorityQ.peekFront();
            currenttime = newEvent.getTime();

            if(newEvent.getIsArrival() == true){
                //process arrival
            }else{
                pDeparture(newEvent, priorityQ, bankQ);
            }
        //I beleive that u put the rest of ur code in here
        //otherwise, it'll go to the error, we can remove exception
        //handling if you want - Rubi 
        }
    }

    //catching error from loadFile just in case
    catch (std::exception &runtime_error) {
        std::cout << runtime_error.what() << std::endl;
    }

};

template<typename T>
void load(PQueue<T> &peventPriorityQueue){
    std::string filename;
    int cTime;
    int eDuration;
    std::cout << "Enter a filename:" << std::endl;
    std::cin >> filename;

    std::ifstream inputfile;
    inputfile.open(filename);

    if(inputfile){  
        while(inputfile){
           inputfile >> cTime >> eDuration;
           peventPriorityQueue.enqueue(Event(true, cTime, eDuration));
        }
        inputfile.close();
    }else{
        throw std::runtime_error("File " + filename + " could not be opened");
    }
}

template<typename T>
void pArrival(Event aEvent, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    eventPriorityQueue.dequeue();
    Event customer = aEvent;
    if(tellAvail && eventBanklineQueue.isEmpty()){
        int departtime = currenttime + customer.getTime();
        eventPriorityQueue.enqueque(Event(false, departtime));
        tellAvail = false;
    }else{
        eventBanklineQueue.enqueque(customer);
    }
}

template<typename T>
void pDeparture(Event dEvent, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    eventPriorityQueue.dequeue();
    if(!eventBanklineQueue.isEmpty()){
        Event customer = eventBanklineQueue.peekFront();
        eventBanklineQueue.dequeque();
        int departtime = currenttime + customer.getTime();
        eventPriorityQueue.enqueque(Event(false, departtime));
    }else{
        tellerAvail = true;
    }
}