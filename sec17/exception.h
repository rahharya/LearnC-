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
};
template<class T>
Stack<T>::Stack(int size)
{
    this->size=size;
    pStk = new T[10];
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

#endif