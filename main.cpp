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
void pArrival(int &currentTime, bool &tellAvail, float &wait, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue);

template<typename T>
void pDeparture(int &currentTime, bool &tellAvail, float &wait, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue);

    int custServ = 0;
    int currenttime = 0;
    bool tellerAvail = true;
    float waitTime = 0;
int main(){
    //all the queues
    PQueue<Event> priorityQ;
    AQueue<Event> bankQ;

    try {
        load(priorityQ);
        std::cout<<"Simulation Begins Processing an arrival event at time: " << priorityQ.peekFront().getTime() <<std::endl;
        while(!priorityQ.isEmpty()){
            Event newEvent = priorityQ.peekFront();
            currenttime = newEvent.getTime();
            if(newEvent.getIsArrival() == true && newEvent.getTime() != 0 && newEvent.geteventDuration() != 0){
                pArrival(currenttime, tellerAvail, waitTime, priorityQ, bankQ);
                custServ++;
            }else if(newEvent.getIsArrival()==false){
                pDeparture(currenttime, tellerAvail, waitTime, priorityQ, bankQ);
            }else break;
        }
        std::cout << "Final Statistics:\n\tTotal Number of people processed: " << custServ << std::endl;
        std::cout << "\tAverage amount of time spent waiting: " << waitTime/custServ << std::endl;
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
void pArrival(int &currentTime, bool &tellAvail, float &wait, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    Event aEvent = eventPriorityQueue.peekFront();
    std::cout << "Processing an arrival event at time: " << currentTime << std::endl;
    if(tellAvail && eventBanklineQueue.isEmpty()){
        int dTime = currentTime + aEvent.geteventDuration();
        eventPriorityQueue.enqueue(Event(false, dTime));
        tellAvail = false;
    }else{
        eventBanklineQueue.enqueue(aEvent);
    }
    eventPriorityQueue.dequeue();
}

template<typename T>
void pDeparture(int &currentTime, bool &tellAvail, float &wait, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    Event dEvent = eventPriorityQueue.peekFront();
    eventPriorityQueue.dequeue();
    if(!eventBanklineQueue.isEmpty()){
        int dTime = currentTime + eventBanklineQueue.peekFront().geteventDuration();
        eventPriorityQueue.enqueue(Event(false, dTime));
        wait = currentTime - dEvent.geteventDuration();
        eventBanklineQueue.dequeue();
    }else{
        tellAvail = true;
    }
    std::cout << "Processing a departure event at time: " << currentTime << std::endl;
}