#include "event.h"

Event::Event(){
    time = 0;
    eventDuration = 0;
    isArrival = false;
}

Event::Event(bool newIsArrival, int newTime){
    time = newTime;
    eventDuration = 0;
    isArrival = newIsArrival;
}

Event::Event(bool newIsArrival, int newTime, int newDuration){
    time = newTime;
    eventDuration = newDuration;
    isArrival = newIsArrival;
}

Event::~Event(){
    //idk
}

void Event::setTime(int newTime){
    time = newTime;
}

int Event::getTime(){
    return time;
}

void Event::seteventDuration(int newDuration){
    eventDuration = newDuration;
}

int Event::geteventDuration(){
    return eventDuration;
}
void Event::setIsArrival(bool newIsArrival){
    isArrival = newIsArrival;
}

bool Event::getIsArrival(){
    return isArrival;
}

bool Event::operator < (const Event& other){
    return time < other.time;
}

bool Event::operator > (const Event& other){
    return time > other.time;
}

/*

void load(PQueue eventPriorityQueue){

};

parse file to store data into events object and then enqueue events into the priority queue.

void pDeparture(bool tellAvail, PQueue eventPriorityQueue, AQueue eventBanklineQueue){

};

Remove departure event from queue. 
Checks priority queue to see if the bank queue is empty. 
    If not and a customer is in line, 
        the new customer will start a transaction with the teller 
        setting the teller to busy. 
        The event is changed to a departure event in the priority queue
    If there is no one in line
        the teller is free.

*/