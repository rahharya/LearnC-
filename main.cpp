#include <iostream>
#include <string>
#include <math.h>
#include "class.h"
#include "complex.h"
#include "rational.h"

using namespace std;

//SECTION 11 INTRODUCTION TO OOPS
    void IntroductiontoOOPS()
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
    }


int main(void)
{
    //IntroductiontoOOPS(); // UNCOMMENT TO USE SECTION 11
    
    Complex c1(1,3), c2(4,2), c3a, c3b;
    cout<<"c1 = "; c1.Display();
    cout<<"c2 = "; c2.Display();
    // 158 Operator Overloading
        c3a=c1.Subtract(c2);
        cout<<"c3a = c1-c2 = "; c3a.Display();
        //or
        c3b=c1-c2;
        cout<<"c3b = c1-c2 = "; c3b.Display();
    // 160 Friend Operator Overloading
        Complex c4=c1+c2;
        cout<<"c4  = c1+c2 = "; c4.Display();
        cout<<"c4  = "<<c4<<endl;
        cout<<endl;
            // cout<<c4;  same with
            // operator<<(cout,c);
    // 164 Student Exercise Rational
        Rational r1(2,3), r2a(3,4),r2b(r2a), r3, r4;
        cout<<"Constructor r1(2,3)  : "<<r1<<endl;
        cout<<"Constructor r2a(3,4) : "<<r2a<<endl;
        cout<<"Constructor r2b(r2a) : "<<r2b<<endl;
        r3=r1+r2b;
        cout<<"         r3 = r1+r2b : "<<r3<<endl;
        r4=r2b-r1;
        cout<<"         r4 = r2b+r1 : "<<r4<<endl;
    system("PAUSE");
    return 0;
}

