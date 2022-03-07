// TEAM MEMBERS: Rubi Dionisio and Andy Tan

#include <iostream>
#include <fstream>
#include "AQueue.h"
#include "PQueue.h"
#include "Event.h"

//variables
int currenttime = 0;
bool tellAvail = true;
float wait = 0;

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
    int custServ = 0;
    try {
        load(priorityQ);
        std::cout<<"Simulation Begins Processing an arrival event at time: " << priorityQ.peekFront().getTime() <<std::endl;
        while(!priorityQ.isEmpty()){
            Event newEvent = priorityQ.peekFront();
            
            if(newEvent.getIsArrival() == true && newEvent.getTime() != 0 && newEvent.geteventDuration() != 0){
                pArrival(newEvent, priorityQ, bankQ);
                custServ++;
            }else if(newEvent.getIsArrival()==false){
                pDeparture(newEvent, priorityQ, bankQ);
                // std::cout << "Processing a departure event at time: " << currenttime << std::endl;
            }else break;
        }
        std::cout << "Final Statistics:\n\tTotal Number of people processed: " << custServ << std::endl;
        std::cout << "\tAverage amount of time spent waiting: " << wait/custServ << std::endl;
    }

    //catching error from loadFile just in case
    catch (std::exception &runtime_error) {
        std::cout << runtime_error.what() << std::endl;
    }

};

//function implementation
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
void pArrival(Event aEvent, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    eventPriorityQueue.dequeue();
    currenttime = aEvent.getTime();
    std::cout << "Processing an arrival event at time: " << currenttime << std::endl;
    if(tellAvail && eventBanklineQueue.isEmpty()){
        // currenttime += aEvent.geteventDuration();
        // std:: cout << "Time in if-statement (pArrival): " << currenttime << std::endl;
        int dTime = currenttime + aEvent.geteventDuration();
        eventPriorityQueue.enqueue(Event(false, dTime));
        tellAvail = false;
    }else{
        eventBanklineQueue.enqueue(aEvent);
    }
}

template<typename T>
void pDeparture(Event dEvent, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    eventPriorityQueue.dequeue();
    //std::cout << "Time in pDepart1: " << depTime << std::endl;
    if(!eventBanklineQueue.isEmpty()){
        Event customer = eventBanklineQueue.peekFront();
        int dTime = currenttime + eventBanklineQueue.peekFront().geteventDuration();
        eventPriorityQueue.enqueue(Event(false, dTime));
        wait += currenttime - dEvent.geteventDuration();
        eventBanklineQueue.dequeue();
        // if(currenttime < customer.getTime()){
        //     currenttime = customer.getTime();
        // }
        //currenttime += customer.geteventDuration();

        //eventPriorityQueue.enqueue(Event(false, currenttime));
    }else{
        tellAvail = true;
    }
    std::cout << "Time in pDepart: " << currenttime << std::endl;
}