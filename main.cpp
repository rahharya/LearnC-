#include <iostream>
#include <string>
#include <math.h>
#include "class.h"
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
        Rectangle *pHeapRect = new Rectangle; // Pointer pointing to Rectangle that created in Heap;
        pHeapRect->length=10;
        pHeapRect->width=22;
        cout<<"Area of pHeapRect      :"<<pHeapRect->area()<<endl;
        cout<<"perimeter of pHeapRect :"<<pHeapRect->perimeter()<<endl;
        delete pHeapRect;
        pHeapRect=nullptr;
    system("PAUSE");
    return 0;
}

