#include <iostream>
#include <string>
#include <math.h>
#include "class.h"
#include "inheritance.h"
#include "inheritance2.h"
using namespace std;

int main(void)
{
    //141. Demo - Class in C++;
        Rectangle r1; // Object Rectangle created in Stack in this sense are the Datamembers saved
        r1.length=10; r1.width=5;
        cout<<"Area of r1      :"<<r1.area()<<endl;
        cout<<"perimeter of r1 :"<<r1.perimeter()<<endl;
        cout<<endl;
    //142. Pointer to an Object in Heap
        //Pointer to Object in Stack
            Rectangle r2;
            Rectangle *pR2;
            pR2=&r2; // Pointer pR2 have the Address of Rectangle r2
            //How to access public Funktion or datamember that pointed by pointer
                pR2->length=20; pR2->width=4;
                cout<<"Area of r2      :"<<pR2->area()<<endl;
                cout<<"perimeter of r2 :"<<pR2->perimeter()<<endl;
                cout<<endl;
        Rectangle *pHeapRect1 = new Rectangle; // Pointer pointing to Rectangle that created in Heap;
        pHeapRect1->length=10;
        pHeapRect1->width=22;
        cout<<"Area of pHeapRect      :"<<pHeapRect1->area()<<endl;
        cout<<"perimeter of pHeapRect :"<<pHeapRect1->perimeter()<<endl<<endl;
        delete pHeapRect1;
        pHeapRect1=nullptr;
    //146. Constructor, Accesor and Mutator 
        HideRectangle r3;
        HideRectangle *pHeapRect2= new HideRectangle(r3);
        pHeapRect2->setLength(10);
        pHeapRect2->setWidth(20);
        cout<<"Area of r3      :"<<r3.area()<<endl;
        cout<<"perimeter of r3 :"<<r3.perimeter()<<endl<<endl;
        cout<<"Area of pHeapRect2       :"<<pHeapRect2->area()<<endl;
        cout<<"perimeter of pHeapRect2  :"<<pHeapRect2->perimeter()<<endl<<endl;
        pHeapRect2->inLineFunction();
        pHeapRect2->nonInLineFunction();
    //166. Inheritance Example
        Cube c1(10,5,3);
        cout<<"c1 = "<<c1<<endl;
    system("PAUSE");
    return 0;
}

