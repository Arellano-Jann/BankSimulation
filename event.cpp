#include "event.h"

Event::Event(){
    time = 0;
    eventDuration = 0;
    eventType = false;
}

Event::Event(bool eventtype, int newTime){
    time = newTime;
    eventDuration = 0;
    eventType = eventtype;
}

Event::Event(bool eventtype, int newTime, int newDuration){
    time = newTime;
    eventDuration = newDuration;
    eventType = eventType;
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
void Event::seteventType(bool newEventType){
    eventType = newEventType;
}

bool Event::geteventType(){
    return eventType;
}

Event Event::operator < (const Event& other){

}

Event Event::operator > (const Event& other){

}

/*


void load(event priority queue){

};

void pDeparture(bool tellAvail, event priority queue, event bankline queue){

};

*/