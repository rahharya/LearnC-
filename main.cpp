#include <iostream>
#include <string>
#include <math.h>
#include "class.h"
#include "inheritance.h"
#include "inheritance2.h"
#include "employeparent.h"
#include "car.h"
using namespace std;

void Section11()
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
        delete pHeapRect2;
        pHeapRect2=NULL;
} 
void Section12()
{
    //166. Inheritance Example
        Cube c1(10,5,3);
        cout<<"c1 = "<<c1<<endl;
        cout<<endl;
}
void Section1314()
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
void Section15()
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
}

int main(void)
{

    system("PAUSE");
    return 0;
}

