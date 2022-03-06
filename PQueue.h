#ifndef P_QUEUE
#define P_QUEUE
#include "queueInterface.h"
template<typename T>
class PQueue:public QueueInterface<T>{
    private:
        int front = 0;
        int back = 100;
        int numItems = 0;
        static const int CAPACITY = 100;
        T queueArray [CAPACITY];
    public:
        bool isEmpty() const;
        bool enqueue(const T& newEntry);
        bool dequeue();
        T peekFront() const;
        ~PQueue() { };
};

#include "PQueue.cpp"
#endif