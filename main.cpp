// TEAM MEMBERS: Rubi Dionisio and Andy Tan

#include <iostream>
#include <fstream>
#include "AQueue.h"
#include "PQueue.h"
#include "event.h"

//parse file to store data into event objects, then enqueue events into the priority queue
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
};

template<typename T>
void pDeparture(bool tellAvail, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){
    Event temp = eventPriorityQueue.peekFront();
    eventPriorityQueue.dequeue();
    if(eveventPriorityQueue.isEmpty()){
        
    }
};
/*

get event from events priority queue
decide if there’s a customer in line, 
    otherwise 
    teller is free. 
    If there’s a customer 
        create departure event and add it to events priority queue, 
        teller is in use 
*/

int main(){
    //all variable (incuding all the queues)
    std::string filename;
    PQueue<Event> priorityQ;
    try {
        load(priorityQ);

        //I beleive that u put the rest of ur code in here
        //otherwise, it'll go to the error, we can remove exception
        //handling if you want - Rubi 
    }

    //catching error from loadFile just in case
    catch (std::exception &runtime_error) {
        std::cout << runtime_error.what() << std::endl;
    }

};