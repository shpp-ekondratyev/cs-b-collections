#ifndef MYSTACK_H
#define MYSTACK_H

#include <cassert> // for assert
#include <iostream>

#include <iomanip> // for setw

template <typename T>
class MyStack
{
private:
    T *stackPtr;                      // a pointer to the stack
    const int size;                   // the maximum number of elements in the stack
    int top;                          // the number of the current stack element
public:
    MyStack(int = 10);                  // the default stack size is 10 items
    MyStack(const MyStack<T> &);          // copy constructor
    ~MyStack();                         // the destructor

    inline void push(const T & );     // put the item in the top of the stack
    inline T pop();                   // remove an item from the top of the stack and return it
    inline void printStack();         // stack output on screen
    inline const T &Peek(int ) const; // the n-th element from the top of the stack
    inline int getStackSize() const;  // get the size of the stack
    inline T *getPtr() const;         // get a pointer to the stack
    inline int getTop() const;        // get the number of the current item in the stack
};

// implementation of a class template MyStack

// Stack constructor
template <typename T>
MyStack<T>::MyStack(int maxSize) :
    size(maxSize) // Initialize constants
{
    stackPtr = new T[size]; // allocate memory for the stack
    top = 0; // initialize the current element zero;
}

// copy constructor
template <typename T>
MyStack<T>::MyStack(const MyStack<T> & otherStack) :
    size(otherStack.getStackSize()) // Initialize constants
{
    stackPtr = new T[size]; // allocate memory for the new stack
    top = otherStack.getTop();

    for(int ix = 0; ix < top; ix++)
        stackPtr[ix] = otherStack.getPtr()[ix];
}

// a destructor function during Stack
template <typename T>
MyStack<T>::~MyStack()
{
    delete [] stackPtr; //Remove stack
}

// function add an item to the stack
template <typename T>
inline void MyStack<T>::push(const T &value)
{
    // check the stack size
    assert(top < size); // current item number must be less than the size of the stack

    stackPtr[top++] = value; // put an item onto the stack
}

// the function deletes the item from the stack
template <typename T>
inline T MyStack<T>::pop()
{
    // check the stack size
    assert(top > 0); // current item number must be greater than 0

    stackPtr[--top]; // delete an element from the stack
}

// the function returns the n-th element from the top of the stack
template <class T>
inline const T &MyStack<T>::Peek(int nom) const
{
  //
  assert(nom <= top);

  return stackPtr[top - nom]; // return the n-th element from the stack
}

// stack output on screen
template <typename T>
inline void MyStack<T>::printStack()
{
    for (int ix = top - 1; ix >= 0; ix--)
        cout << "|" << setw(4) << stackPtr[ix] << endl;
}

// return the size of the stack
template <typename T>
inline int MyStack<T>::getStackSize() const
{
    return size;
}

// return a pointer to the stack (for copy constructor)
template <typename T>
inline T *MyStack<T>::getPtr() const
{
    return stackPtr;
}

// return the size of the stack
template <typename T>
inline int MyStack<T>::getTop() const
{
    return top;
}

#endif // MYSTACK_H
