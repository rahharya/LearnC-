#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void Display()
{
    cout<<"Funktion executed: Hallo"<<endl;
}
int Max(int x, int y){
    return x>y?x:y;
}
int Min(int x, int y){
    return x<y?x:y;
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

int main(void)
{
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
    system("PAUSE");
    return 0;
}

