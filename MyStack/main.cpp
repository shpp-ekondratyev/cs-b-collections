#include <iostream>

using namespace std;

#include "mystack.h"

int main()
{
    MyStack<char> stackSymbol(5);
    int ct = 0;
    char ch;
    cout << "Enter 5 characters for the push to stack :";
    while (ct++ < 5)
    {
        cin >> ch;
        stackSymbol.push(ch); // put the items in the stack
    }

    cout << endl;

    stackSymbol.printStack(); // printing stack

    cout << "\n\nRemove an element from the stack\n";
    stackSymbol.pop();

    stackSymbol.printStack(); // printing stack

    MyStack<char> newStack(stackSymbol);

    cout << "\n\nWorked copy constructor!\n";
    newStack.printStack();

    cout << "The second element in the queue:"<< newStack.Peek(2) << endl;

    return 0;
}
