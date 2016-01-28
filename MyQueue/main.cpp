#include <iostream>

using namespace std;

#include "myqueue.h" // connect the class template

int main ()
{
    MyQueue<int> queue;

    for(int i = 0; i < 10; i++){
        queue.enqueue(i);
    }

    cout << "Size: " << queue.size() << endl;

    for(int i = 0; queue.size(); i++){
        cout << queue.dequeue()<< endl;
    }

  return 0;
}
