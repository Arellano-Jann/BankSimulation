#include "Event.h"

Event::Event(){
    time = 0;
    eventDuration = 0;
    isArrival = true;
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
    //validates if the time is the same
    //arrival has priority over departure event
    return (time == other.time && isArrival) || time < other.time;
}

bool Event::operator > (const Event& other){
    //validates if the time is the same
    //arrival has priority over departure event
    return (time == other.time && isArrival) || time > other.time;
}