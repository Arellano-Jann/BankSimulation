// TEAM MEMBERS: Rubi Dionisio and Andy Tan

#include <iostream>
#include <fstream>
#include "AQueue.h"
#include "PQueue.h"
#include "Event.h"

//parse file to store data into event objects, then enqueue events into the priority queue
template<typename T>
void load(PQueue<T> &peventPriorityQueue);

template<typename T>
void pArrival(Event aEvent, bool &tAvail, int &cTime, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue);

template<typename T>
void pDeparture(Event dEvent, bool &tAvail, int &cTime, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue);

int main(){
    //all the queues
    PQueue<Event> priorityQ;
    AQueue<Event> bankQ;
    int currenttime = 0, custServ = 0;
    bool tellAvail = true;
    try {
        load(priorityQ);
        std::cout<<"Simulation Begins Processing an arrival event at time: " << priorityQ.peekFront().getTime() <<std::endl;
        while(!priorityQ.isEmpty()){
            Event newEvent = priorityQ.peekFront();
            std::cout<< newEvent.getTime() <<std::endl;
            currenttime += newEvent.getTime();
            
            if(newEvent.getIsArrival() == true){
                std::cout << "Processing an arrival event at time: " << currenttime << std::endl;
                pArrival(newEvent, tellAvail, currenttime, priorityQ, bankQ);
                custServ++;
            }else{
                std::cout << "Processing a departure event at time: " << currenttime << std::endl;
                pDeparture(newEvent, tellAvail, currenttime, priorityQ, bankQ);
                //custServ++;
            }
        }
        std::cout << "Final Statistics:\n\tTotal Number of people processed: " << custServ << std::endl;
        std::cout << "\tAverage amount of time spent waiting: " << std::endl;
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
        while(inputfile >> cTime >> eDuration){
           peventPriorityQueue.enqueue(Event(true, cTime, eDuration));
        }
        inputfile.close();
    }else{
        throw std::runtime_error("File " + filename + " could not be opened");
    }
}

template<typename T>
void pArrival(Event aEvent, bool &tAvail, int &cTime, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    eventPriorityQueue.dequeue();
    if(tAvail && eventBanklineQueue.isEmpty()){
        int departtime = cTime + aEvent.getTime();
        eventPriorityQueue.enqueue(Event(false, departtime));
        tAvail = false;
    }else{
        eventBanklineQueue.enqueue(aEvent);
    }
}

template<typename T>
void pDeparture(Event dEvent, bool &tAvail, int &cTime, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    eventPriorityQueue.dequeue();
    if(!eventBanklineQueue.isEmpty()){
        Event customer = eventBanklineQueue.peekFront();
        eventBanklineQueue.dequeue();
        int departtime = cTime + customer.getTime();
        eventPriorityQueue.enqueue(Event(false, departtime));
    }else{
        tAvail = true;
    }
}