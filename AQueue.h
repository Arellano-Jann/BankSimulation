#ifndef ARR_QUEUE
#define ARR_QUEUE

#include "queueInterface.h"
template<typename T>
class AQueue:public QueueInterface<T>{
    private:
        int front = 0;
        int back = 0;
        int numItems = 0;
        static const int CAPACITY = 100;
        T queueArray [CAPACITY];
    public:
        bool isEmpty() const;
        bool enqueue(const T& newEntry);
        bool dequeue();
        T peekFront() const;
        ~AQueue() { };
};

#include "AQueue.cpp"

#endif