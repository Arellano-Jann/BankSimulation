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