// TEAM MEMBERS: Rubi Dionisio and Andy Tan

#include <iostream>
#include <fstream>
#include "aQueue.h"
#include "pQueue.h"
#include "event.h"

//parse file to store data into event objects, then enqueue events into the priority queue
template<typename T>
void load(PQueue<T> &peventPriorityQueue){

};

template<typename T>
void loadFile(std::string file, PQueue<T> &peventPriorityQueue){
    std::ifstream inputfile;
    inputfile.open(file);

    if(inputfile){  
        while(inputfile){
           // inputfile >> cTime >> eDuration;
                
        }
    }else{
        throw std::runtime_error("File " + file + " could not be opened");
    }
};

template<typename T>
void pDeparture(bool tellAvail, PQueue<T> &eventPriorityQueue, AQueue<T> &eventBanklineQueue){

};
/*
Remove departure event from queue. 
Checks priority queue to see if the bank queue is empty. 
    If not and a customer is in line, 
        the new customer will start a transaction with the teller 
        setting the teller to busy. 
        The event is changed to a departure event in the priority queue
    If there is no one in line
        the teller is free.

*/

int main(){
    //all variable (incuding all the queues)
    std::string filename;
    PQueue<Event> priorityQ;
    try {
        std::cout << "Enter a filename:" << std::endl;
        std::cin >> filename;
        loadFile(filename, priorityQ);

        //I beleive that u put the rest of ur code in here
        //otherwise, it'll go to the error, we can remove exception
        //handling if you want - Rubi 
    }

    //catching error from loadFile just in case
    catch (std::exception &runtime_error) {
        std::cout << runtime_error.what() << std::endl;
    }
    


};