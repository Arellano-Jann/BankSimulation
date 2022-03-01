#ifndef ARR_QUEUE
#define ARR_QUEUE

#define ARR_SIZE 100

template<typename T>
class AQueue:public QueueInterface{
    <typename T> queueArray [];
    public:
        bool isEmpty() const = 0;
        bool enqueque(const T& newEntry) = 0;
        bool dequeue() = 0;
        T peekFront() const = 0;
        ~QueueInterface() { }
};

#include "aQueue.cpp"

#endif