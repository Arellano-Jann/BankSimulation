#ifndef P_QUEUE
#define P_QUEUE
#include "queueInterface.h"
template<typename T>
class PQueue:public QueueInterface<T>{
    private:
        int front;
        int back;
        int numItems;
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