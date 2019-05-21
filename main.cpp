#include <iostream>
#include <string>
#include <math.h>
#include "class.h"
#include "complex.h"
#include "rational.h"
#include "funktionsect.h"
#include "inheritance.h"
#include "inheritance2.h"
#include "employeparent.h"
#include "sec15\car.h"
#include "sec16\friend.h"
#include "sec16\inner_nested.h"
using namespace std;

void Section10_Function()
{    
    cout<<"Global & Local Variabel, Scooping Rule"<<endl;
        //Code and Global Variable are saved in main
        int scope=20;
        {
            int scope=30;
            cout<<"     Scooping Rule|scope inside:"<<scope<<endl;
        }
        cout<<"     Scooping Rule|scope main  :"<<scope<<endl;
        cout<<"     Scooping Rule|scope global:"<<::scope<<endl;
        cout<<endl;

    cout<<"Static Variable"<<endl;
        ExampleStaticVariabel();
        ExampleStaticVariabel();
        ExampleStaticVariabel();
        ExampleStaticVariabel();
        cout<<endl;

    cout<<"Funtion Overloading and Default Argument"<<endl;
        cout<<"     F Ovrload 2 Arg int  : "<<Add(10,34)<<endl;
        cout<<"     F Ovrload 3 Arg int  : "<<Add(10,34,20)<<endl;
        cout<<"     F Ovrload 2 Arg float: "<<Add(10.5f,5.23f)<<endl;
        cout<<endl;
    cout<<"Function Template"<<endl;
        cout<<"     F Template| int Max  : "<<Max(10,5)<<endl;
        cout<<"     F Template| float Max: "<<Max(10.5f,5.23f)<<endl;
        cout<<endl;
    cout<<"Parameter Passing"<<endl;
        int valA=10, valB=33;
        cout<<"    Pass by Val| MAIN before: valA = "<<valA<<" valB = "<<valB<<endl;
        Swap(valA,valB);
        cout<<"    Pass by Val| MAIN after : valA = "<<valA<<" valB = "<<valB<<endl;
        cout<<endl;
        cout<<"    Pass by Add| MAIN before: valA = "<<valA<<" valB = "<<valB<<endl;
        Swap(&valA,&valB);
        cout<<"    Pass by Add| MAIN after : valA = "<<valA<<" valB = "<<valB<<endl;
        cout<<endl;
        cout<<"    Pass by Ref| MAIN before: valA = "<<valA<<" valB = "<<valB<<endl;
        SwapByRef(valA,valB);
        cout<<"    Pass by Ref| MAIN after : valA = "<<valA<<" valB = "<<valB<<endl;
}
void Section11_Object_Oriented_Programming()
{
    //141. Demo - Class in C++;
        Rectangle r1; // Object Rectangle created in Stack in this sense are the Datamembers saved
        r1.length=10; r1.width=5;
        cout<<"Area of r1      :"<<r1.area()<<endl;
        cout<<"perimeter of r1 :"<<r1.perimeter()<<endl;
        cout<<endl;
    cout<<"Return Funktion"<<endl;
        int *pInt = CreateHeapArray(4);
        cout<<"     Ret by Add| pInt from main pointing to : "<<pInt<<endl;
        cout<<"     Ret by Add| pInt = {"<<*pInt<<","<<pInt[1]<<","<<*(pInt+2)<<","<<pInt[3]<<"}"<<endl;
        int nVal=10;
        cout<<"     Ret by Ref| Before | nVal = a = "<<nVal<<endl;
        cout<<"     Ret by Ref| After  | nVal = a = RetValue(nVal) = "<<RetValue(nVal)<<endl;
        RetValue(nVal)=45;
        cout<<"     Ret by Ref| After  | RetValue(nVal) with Value = "<<RetValue(nVal)<<endl;
    cout<<"Rekursive Function"<<endl;
        RekursiveFunction(5);
        cout<<"Fibonaci[9] : "<<Fibonaci(9)<<endl;
}
void Section11_IntroductiontoOOPS()
{
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
        delete pHeapRect2;
        pHeapRect2=NULL;
} 
void Section12_Operator_Overloading()
{
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

    //166. Inheritance Example
        Cube cube1(10,5,3);
        cout<<"c1 = "<<c1<<endl;
        cout<<endl;
}
void Section13_14_Inheritance()
{
    //179. Student Exercise #11 Inheritance Employee
    
    // Parent Class Pointer pointing at ChildClass is like we take the Employee-Feature from FullTimeEmployee-Feature
    // that means the Element that can be accessed is only Element from ParentClass
    // it's just like take one special feature of an Auto, for example Auto have so many feature like Tire, Door, Multimedia
    // then it s like "i want to look specificaly at Multimedia Class from Car Class"
    // therefore it cant worked otherwise : "i want to look at feature 'Car' from Tire"
    Employee *pEmploye;
    pEmploye = new FullTimeEmployee("Arya",1,3880);
    cout<<"Employe Name is "<<pEmploye->getName()<<" and his/her Id is "<<pEmploye->getEmployeId()<<endl;
    //pEmploye->getSalary() // class "Employee" has no member "getSalary"
    // we also cant pointing at ParentClass using ChildClass Pointer because ParentClass didnt have some Feature that ChildClass has
        // FullTimeEmployee *pEmployee = new Employe("Arya",1);    // <== ERROR
    
    PartTimeEmployee Andre("Andre",2,28);
    
    cout<<Andre<<endl;
}
void Section15_Polymorphism()
{
    // 185. Function Overiding
        //Car car1; //object of abstract class type "Car" is not allowed: -- function "Car::Start" is a pure virtual function -- function "Car::Stop" is a pure virtual function
            // Abstract Class, we can't have Object from Abstract Classes, only pointer deklaration
            // If a Base Class (here Car) have Functions that all concrete is, than it is reusability Inheritance
            //                                 some concrete and some pure virtual funktion, then it's for reusability aswell polymorphism. This classes called Abstract Class
            //                                 only pure virtual Functions, then it's only for Polymophism. Such classes called Interface Abstract Class


        Innova innova1;
        //car1.Start();
        innova1.Start();
    // 186. Virtual Functions
        Car *car2 = new Innova();
        car2->Start(); // This will call Start Funktion from Parent Class
        car2->Stop();  // This will call Stop Funktion from Child Class because Stop Funktion in Parent is virtual
        car2= new Swift();
        car2->Start();
        HideRectangle ChildRect(5,3);
        Shape *pRect = &ChildRect;
        cout<<pRect->area()<<endl;
        Shape *pCircle = new Circle(7);
        cout<<pCircle->perimeter()<<endl;
        cout<<Innova::GetPrice();
        
}
void Section16_Friend_and_Static_Members_or_Inner_Classe()
{
    //194. Friend Function and Classes
        Your y1;
        y1.fun(); // Initialisieren the value of Mine Classes that inside Your Classes
        int a,b,c;
        y1.getA(a);
        y1.getB(b);
        y1.getC(c);
        cout<<"Mine.count(static var) = "<<Mine::count<<" | a = "<<a<<" | b = "<<b<<" | c = "<<c<<endl;
        Your y2;
        cout<<"Mine.count(static var) = "<<y2.m.count<<" | a = "<<a<<" | b = "<<b<<" | c = "<<c<<endl;
        Mine m1;
        cout<<"Mine.count(static var) = "<<Mine::getCount()<<" | a = "<<a<<" | b = "<<b<<" | c = "<<c<<endl;
    //200. Inner/ Nested Class
        Outer out1;
        out1.fun();
        LinkedList list1;
        int input;
        start:
        cout<<"Enter Input : "; cin>>input;
        if(input==0) goto stop;
        else
        {
            list1.AddNode(input);
            goto start;
        }      
        stop:
        list1.Display();
}

int main(void)
{
    // Section11_IntroductiontoOOPS();
    // Section12_Operator_Overloading();
    Section13_14_Inheritance();
    // Section15_Polymorphism();
    // Section16_Friend_and_Static_Members_or_Inner_Classe();

    system("PAUSE");
    return 0;
}

    