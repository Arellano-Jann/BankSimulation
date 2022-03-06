#ifndef EVENT_H
#define EVENT_H

class Event{
    private:
    int time;
    int eventDuration;
    bool isArrival;

    public:
    //constructors
    Event();
    Event(bool newIsArrival, int newTime);
    Event(bool newIsArrival, int newTime, int newDuration);
    ~Event() {};

    //getters and setters
    void setTime(int newTime);
    int getTime();
    void seteventDuration(int newDuration);
    int geteventDuration();
    void setIsArrival(bool newIsArrival);
    bool getIsArrival();

    //operator overloading
    bool operator < (const Event& other);
    bool operator > (const Event& other);

};

#endif