#include <iostream>

using namespace std;

#include "mystack.h"

int main()
{
    MyStack<int> stack;

    for (int i = 0; i < 10; i++){
        stack.push(i);
    }

    cout << "Size: " << stack.size() << endl;
    cout << "Peek: " << stack.top() << endl;
    cout << "isEmpty: " << stack.isEmpty() << endl;

    for (int i = 0; i < 10; i++){
        int a = stack.pop();
        cout << "Pop: " << a << endl;
    }

    stack.clear();

    cout << "isEmpty: " << stack.isEmpty() << endl;

    return 0;
}
