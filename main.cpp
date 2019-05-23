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
#include "sec17\exception.h"
using namespace std;


    #define PI 3.1425 // Symbolic constant
  //  #define c cout
    #define SQRT(x) (x*x) // Create funktion
    #define MSG(x) #x // Change the x into string

namespace First
{
    void func()
    {
        cout<<"First"<<endl;
    }
}

namespace Second
{
    void func()
    {
        cout<<"Second"<<endl;
    }
}


void Section09_Pointer()
{
    //103. Pointer Introduction
    cout<<"---==Pointer Introduction==---"<<endl<<endl;

        /* Pointer is to used to:
            1. Accesing Heap Memory
            2. Accesing File, Keyboard, Printer or another Hardware that connected
        */ 

        int x=10; 
        int *px=&x; //Declaration and Initialisation of Pointer

        /* It can also be written like this
            int x=10;
            int *px;    //Initialisation of Pointer
            px=&x;      //Declaration the value of px with Adresse of x
        */

        cout<<"Value of integer x        : "<<x<<endl;
        cout<<"Adresse of Integer x      : "<<&x<<endl;
        cout<<"Value of Pointer px       : "<<px<<endl;
        cout<<"Adresse of Pointer px     : "<<&px<<endl;
        cout<<"The value that stored in x: "<<*px<<endl;  //Dereferencing Pointer
        cout<<endl<<endl;

    cout<<"---==Pointer Arithmetic==---"<<endl<<endl;

        int B[5]={1,2,3,4,5};
        int *pB = B;        // Here we dont need the & Symbol infront of B because B is already a Adresse from the first Element of Array B (here B[0])
        
        for(int i=0;i<5;i++)
        {
            //cout<<"B["<<i<<"] Add: "<<pB+i<<" | Val: "<<*(pB+i)<<endl;
            //oder
            cout<<"B["<<i<<"] Add: "<<pB+i<<" | Val: "<<pB[i]<<endl;
        };
        
        cout<<"\nAdresse of B[0] : "<<pB<<endl;
        cout<<"Value of B[0]   : "<<*pB<<endl;

        //Incrementation from an pointer will show the next component of an Array because Array is always saved/structed in row
        pB++;
        cout<<"Adresse of B[1] : "<<pB<<endl;
        cout<<"Value of B[1]   : "<<*pB<<endl;
        //Decrementation
        pB--;
        cout<<"Adresse of B[0] : "<<pB<<endl;
        cout<<"Value of B[0]   : "<<*pB<<endl;
        pB+=2;
        cout<<"Adresse of B[2] : "<<pB<<endl;
        cout<<"Value of B[2]   : "<<*pB<<endl;
        pB-=2;
        cout<<"Adresse of B[2] : "<<pB<<endl;
        cout<<"Value of B[2]   : "<<*pB<<endl;
        // Printing the Value without moving the pointer;
        cout<<"\nValue of *(pB+2): "<<*(pB+2)<<endl;
        cout<<"Value of pB     : "<<pB<<endl;
        cout<<"Value of *pB[2] : "<<pB[2]<<endl<<endl;
        int *pBlast = &B[4]; //Here is '&' Symbol needed because B[4] is pointing to integer not an Array
        cout<<"Adresse of B[4] : "<<pBlast<<endl;
        cout<<"Value of B[4]   : "<<*pBlast<<endl;
        cout<<endl;


    cout<<"--=Reference=--"<<endl<<endl;
        //Referencing mean that it will be create another ilias for the variable
        // j have the value of 10
        // rk have the same Adress with j, so automaticly rk also have the value of 10
        // if value from one variable changed that it will be also changed for both of the variable
        int j = 10;
        int &rk = j;
        cout <<"Start         --> j= "<<&j<<":"<<j<<" |rk= "<<&rk<<":"<<rk<<endl;
        j+=1;
        cout <<"After (j+=1)  --> j= "<<&j<<":"<<j<<" |rk= "<<&rk<<":"<<rk<<endl;
        rk+=2;
        cout <<"After (rk+=2) --> j= "<<&j<<":"<<j<<" |rk= "<<&rk<<":"<<rk<<endl;
        cout<<endl<<endl;
    cout<<"--=Funktion Pointer=--"<<endl<<endl;
        void (*pDisplay)();                                 //<-- Declaration
        pDisplay=Display;                                   //<-- Initialisiation
        cout<<"Adress of the Display "<<pDisplay<<endl;
        (*pDisplay)();                                      //<-- Call
        cout<<endl;

        int (*pMaxMin)(int,int);
        pMaxMin=Max;
        cout<<"Max is called "<<(*pMaxMin)(10,5)<<endl;
        pMaxMin=Min;
        cout<<"Min is called with the same Pointer different Value "<<(*pMaxMin)(10,5)<<endl;

    cout<<"---==Heap Memory Allocation==---"<<endl<<endl;

        // Variable that located in the Stack will be automaticlly deleted when get out of the scope
        // For Variable that located in Heap will be still there until the Program end or until the Memory deleted
        // Therefore it's important to delocated memory that not used (delete)
        // When the variable that in Heap located not pointed by any pointer that mean we can't access or delete the variable
        // and that is called 'Memory Leak' 

        int nHeapArraySize;
        int A[5]={1,2,3,4,5};   // Stack Array (the size of the Stack Array is cannot be modified)
        cout<<"Enter size of the Heap Array: "; cin>>nHeapArraySize;
        int *pA = new int[nHeapArraySize];      // Pointer located in Stack and that pointer will be 
                                                // pointing Array that located in Heap Memory

        //Modify the size of Heap Array                                        
        cout<<"Enter new Size of the same Heap Array: "; cin>>nHeapArraySize;
        delete [] pA;                           // delete heap memory that pA pointed
        pA = new int[nHeapArraySize];           // This will be pointing the same HeapArray because it's using the same Pointer 
                                                // That means with HeapArray we can modify it's size 
        pA[4]=5;                // [0][0][5][0][0] -> HEAP
        /* It can also be written like this
            int *pA;
            pA = new int[5];
        */
        delete [] pA;           // delete heap memory that pA pointed
        pA=NULL;                // delete the value of the pA that already deleted
        /*Note:
            it's important to delete the memory first before setting the pointer value to null
            when the pointer deleted first before the heap memory deleted that it will only delete
            the adresse of the Heap Variable but wont delete the Variable from the heap (called 'MEMORY LEAK')
        */

    //Problem Using Pointer
    /*  1.  Uninitialized Pointer
            WRONG!! 
                int *p; //declaration of Pointer
                *p = 25 //value of adresse that pointed is p but it didnt point any adresse
            RIGHT!!
                int x = 25;
                (1) int *p;
                    p = &x;
                (2) int *p = &x;
                (3) p = (int*)0x051H; //pointing into spesifik adresse
                (4) p = new int[5];*/
    /*  2.  Memory Leak
            Heap Memory was used but no pointer pointing it value
            It can't be deleted or accesed;
            WRONG!!
                int *p = new int[5];
                p=NULL;
                delete[] p; <-- ERROR because p is not pointing anywhere, it was deleted before
            RIGHT!!
                int *p = new int[5];
                delete[] p;
                p=NULL; // or p=nullptr; // or p=0;*/
    /*  3.  Dangling Pointer
            If the Pointer was deleted by another Methods or Funktion and we try to access it again.
            WRONG!!
                void hallo(int *q)
                { 
                    ...
                    delete []q;
                }

                void main()
                {
                    int *p = new int[5];
                    ...
                    hallo(p);
                    cout<<*p;  <-- ERROR because the value is already deleted trought Method 'hallo'
                }          */
}
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
void Section17_Exception_Handling()
{
    int a = 10, b, c;
    startsect17:
    cout<<"(a/b) | a = "<<a<<" | Enter value of b : "; cin>>b;
    try{
        // if(b==0) throw 1010;
        // c=a/b;

        // throw and catch between Functions
        c= Division(a,b);
        cout<<"(a/b) = "<<c<<" | a = "<<a<<" | b = "<<b<<endl;
    } 
    catch(MyException e)
    {
       cout<<"Division by Zero | MyEception : "<<endl;
    }
    catch (int e)
    {
       cout<<"Division by Zero | ERROR CODE : int "<<e<<endl;
    }
    catch (double e)
    {
       cout<<"Division by Zero | ERROR CODE : dbl "<<e<<endl;
    }
    catch (...) // catch all handler must come last
    {
       cout<<"Division by Zero | ERROR CODE : all "<<endl;
    }
    goto startsect17;
};
void Section18_Templete_Function_and_Classes()
{
    Stack<int> cStack(5); int input;
    startsect18:
    cout<<"Push(1) or Pop(2) : "; cin>>input;
    if(input==1) 
    {
        cout<<"Push int: "; 
        cin>>input; 
        cStack.Push(input);
    }
    else if (input==2)
    {
        cStack.Pop(input);
        cout<<"Pull int: "<<input<<endl;
    }
    cStack.Display();
    goto startsect18;
}
void Section19_Constant_Prepocessor_Directives_and_Namespace()
{
    //214. Constant Qualifier
        int x=10,y=20,z=30;
        //LOCK ON VALUE
            // it's not the pointer that constant but the value that pointer pointing at is constant
            const int *ConstVal=&x; 
            // *ValuePtr+=1; error: increment of read-only location '* ValuePtr'
            cout<<*ConstVal<<endl; // showing the constant value of x
            ConstVal=&y; // change the value of pointer to address from y
            cout<<*ConstVal<<endl;
            y++; // y is not constant, therefor we can change its value
            cout<<*ConstVal<<endl;

        //LOCK ON POINTER
            int *const ConstPtr = &z; // this mean that the pointer value is constant not the Value that pointer pointing to
            // ConstPtr=&x; << ERROR
            *ConstPtr+=1;
            cout<<*ConstPtr<<endl;

        //LOCK ON VALUE AND POINTER
            int w=40;
            const int *const ConstPtrAndValue = &w;
            // ConstPtrAndValue=&x; //<< ERROR
            // *ConstPtrAndValue+=1; //<< ERROR
            cout<<*ConstPtrAndValue<<endl;
        //CONSTANT FUNCTION
            HideRectangle ConstRect1(3,4);
            cout<<ConstRect1.getLength()<<endl;
    // 217. Prepocessor Directives
        cout<<PI<<endl; // PI is not a variable
        cout<<MSG(Hello World)<<endl;
    // 218. Namespaces
        // When there is multiple same name global function we can use namespace to separate the Function
        // ERROR EXAMPLE
        // 1. func(); // There are no func() funktion in the global Function because it is in the namespace
        First::func();




}
int main(void)
{
    // Section11_IntroductiontoOOPS();
    // Section12_Operator_Overloading();
    // Section13_14_Inheritance();
    // Section15_Polymorphism();
    // Section16_Friend_and_Static_Members_or_Inner_Classe();
    Section19_Constant_Prepocessor_Directives_and_Namespace();
    system("PAUSE");
    return 1;
}

    