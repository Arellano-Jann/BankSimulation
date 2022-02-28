#ifndef EVENT_H
#define EVENT_H

class Event{
    private:
    int time;
    int eventDuration;
    bool eventType; //can change to isArrival or isDeparture

    public:
    //constructors
    Event();
    Event(bool eventtype, int newTime);
    Event(bool eventtype, int newTime, int newDuration);
    ~Event();

    //getters and setters
    void setTime(int newTime);
    int getTime();
    void seteventDuration(int newDuration);
    int geteventDuration();
    void seteventType(bool newEventType);
    bool geteventType();

    //operator overloading
    Event operator < (const Event& other);
    Event operator > (const Event& other);

};

#endif