#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
using namespace std;

class MyException: exception
{

};

class StackOverFlow: exception{};
class StackUnderFlow: exception{};

template<class T>
class Stack{
        int top=-1;
        int size;
        T *pStk;
    public:
        Stack(int size);
        void Push(T nData);
        void Pop(T &nData);
        void Display()
        {
            cout<<"Stack : ";
            for(int i=0; i<=top;i++)
            {
                cout<<pStk[i]<<" ";
            }
            cout<<endl;
        }
        ~Stack();
};
template<class T>
Stack<T>::Stack(int size)
{
    this->size=size;
    pStk = new T[this->size];
}

template<class T>
void Stack<T>::Push(T nData)
{
    if (top==size-1) throw StackOverFlow();
    top++;
    pStk[top]=nData;
}

template<class T>
void Stack<T>::Pop(T &nData)
{
    if (top==-1) throw StackUnderFlow();
    nData=pStk[top];
    top--;
}

template<class T>
Stack<T>::~Stack()
{
    // because we have allocated some Object in Heap Memory
    // the the memory have to be deleted when the Object destroyed
    delete []pStk;
    pStk=nullptr;
    cout<<"Stack deleted and Heap Memory Allocation also deleted to avoid MEM-LEAK"<<endl;
}

#endif