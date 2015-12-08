#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <cassert>
#include <iostream>

template<typename T>
class MyQueue
{
private:
    T *queuePtr;     // a pointer to a queue
    const int size;  // the maximum number of items in the queue
    int begin,       // queue
        end;         // the end of the queue
    int elemCT;      // counter items
public:
    MyQueue(int =10);          // the default constructor
    MyQueue(const MyQueue<T> &); // copy constructor
    ~MyQueue();                // the destructor

    void enqueue(const T &); // add an element to the queue
    T dequeue(); // Remove element from a queue
    void printQueue();
};

// implementation of template class MyQueue

// the default constructor
template<typename T>
MyQueue<T>::MyQueue(int sizeQueue) :
    size(sizeQueue), // Initialize constants
    begin(0), end(0), elemCT(0)
{
    // additional position will help us distinguish between the end and the beginning of the queue
    queuePtr = new T[size + 1];
}

// copy constructor
template<typename T>
MyQueue<T>::MyQueue(const MyQueue &otherQueue) :
    size(otherQueue.size) , begin(otherQueue.begin),
    end(otherQueue.end), elemCT(otherQueue.elemCT),
    queuePtr(new T[size + 1])
{
    for (int ix = 0; ix < size; ix++)
        queuePtr[ix] = otherQueue.queuePtr[ix]; // copy queue
}

// destructor class MyQueue
template<typename T>
MyQueue<T>::~MyQueue()
{
    delete [] queuePtr;
}

// the ability to add an element to the queue
template<typename T>
void MyQueue<T>::enqueue(const T &newElem)
{
    // check whether an empty seat in the queue
    assert( elemCT < size );

    // Note that the queue starts filled with index 0
    queuePtr[end++] = newElem;

    elemCT++;

    // Note that the queue starts filled with index 0
    if (end > size)
        end -= size + 1; // return end on top of the queue
}

// return end on top of the queue
template<typename T>
T MyQueue<T>::dequeue()
{
    // check whether the queue items
    assert( elemCT > 0 );

    T returnValue = queuePtr[begin++];
    elemCT--;

    // checking circular fill the queue
    if (begin > size)
        begin -= size + 1; // return behin the queue

    return returnValue;
}

template<typename T>
void MyQueue<T>::printQueue()
{
    cout << "Queue: ";

    if (end == 0 && begin == 0)
        cout << " an empty\n";
    else
    {
        for (int ix = end; ix >= begin; ix--)
            cout << queuePtr[ix] << " ";
        cout << endl;
    }
}

#endif // MyQueue_H
