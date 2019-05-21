#ifndef INNER_H
#define INNER_H

#include<iostream>
using namespace std;

class Outer
{
    //Outer Class can access all Element in Inner Class
    public:
        int a = 10;
        static int b;

        void fun()
        {
            InnerObject.show();
            cout<<"This is from Outer Class | here is the value of x in InnerClass : "<<InnerObject.x<<endl;
        }

        class Inner
        {
            // Inner Class can only access static variable of Inner Class
            public:
                int x = 25;
                void show()
                {
                    cout<<"This is from Inner Class"<<b<<endl;
                }
        };

        Inner InnerObject;
};

int Outer::b=11234;

class LinkedList
{
    private:
        class Node
        {
            public:
                int data;
                
                int ID;
            
                Node *next;
                Node(int data=0){
                    NodeId++;
                    ID = NodeId;
                    this->data=data;
                }
                int getId()
                {
                    return ID;
                }
                Node *getNextAddress()
                {
                    return next;
                }
                int getData()
                {
                    return data;
                }
        };

        static int NodeId;
        Node *tempNode;
        Node *Head = NULL;

    public:
        LinkedList()
        {
        }
        LinkedList(Node FirstNode)
        {
            Head = &FirstNode;
        }
        LinkedList(int FirstNodeData)
        {        
            Head = new Node(FirstNodeData);
        }
        void AddNode(int NodeData)
        {
            tempNode= new Node();
            tempNode->data = NodeData;
            tempNode->next = Head;
            Head = tempNode;
        }
        void Display()
        {
            
            tempNode = Head;
            do 
            {
                cout<<"HEAD: "<<Head<<" | ";
                cout<<"ID: "<<tempNode->getId()<<" | Addresse : "<<tempNode<<" | Value : "<<tempNode->getData()<<endl;
                tempNode=tempNode->getNextAddress();
            }
            while(tempNode->getNextAddress()!=nullptr);
        }

        
};

int LinkedList::NodeId = 0;

#endif