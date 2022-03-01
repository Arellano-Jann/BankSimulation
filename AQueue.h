#ifndef ARR_QUEUE
#define ARR_QUEUE

#include "queueInterface.h"
template<typename T>
class AQueue:public QueueInterface<T>{
    private:
        int front;
        int back;
        int numItems;
        static const int CAPACITY = 100;
        T queueArray [CAPACITY];
    public:
        bool isEmpty() const;
        bool enqueque(const T& newEntry);
        bool dequeue();
        T peekFront() const;
        ~AQueue() { }
};

#include "AQueue.cpp"

#endif