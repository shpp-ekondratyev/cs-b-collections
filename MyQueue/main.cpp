#include <iostream>

using namespace std;

#include "myqueue.h" // connect the class template

int main ()
{
    MyQueue<char> firstQueue(14); // class queue object

    int ct = 1;
    char ch;
    cout << "Add items to the queue :\n";
    while (ct++ < 14)
    {
        cin >> ch;
        firstQueue.enqueue(ch);
    }

    firstQueue.printQueue(); // output queue
    cout << "After removing 3-th items from the queue :\n";
    // remove an item from the queue
    firstQueue.dequeue();
    firstQueue.dequeue();
    firstQueue.dequeue();

    firstQueue.printQueue(); // output queue

    cout << "\n\nWorked copy constructor:\n";
    MyQueue<char> newQueue(firstQueue);

    newQueue.printQueue(); // output queue

  return 0;
}
