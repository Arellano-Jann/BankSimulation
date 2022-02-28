
template<typename T>
class AQueue:public QueueInterface{
    
    public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueque(const T& newEntry) = 0;
    virtual bool dequeue() = 0;
    virtual T peekFront() const = 0;
    virtual ~QueueInterface() { }
};