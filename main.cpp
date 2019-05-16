#include <iostream>
#include <string>
#include <math.h>

using namespace std;


void _85C11NewFeatureWithAuto()
{
    float fA[]={3,6.56f,7.345f,6.123f}; // sometimes we don't need to decleare the size of the Array
    cout<<"New Feature from C11 : auto datatype for Array or Vector"<<endl; cout<<"A[]: ";
    for(auto x:fA) cout<<x<<" "; cout<<endl;//it works like for each, with auto datatyp that means that it will detect the datatyp from A by itself
    // it can also written like this when we already now what datatype that the Array/Vector
    //for(char i:A) cout<<i<<" ";

    //Summe from all Element of the Array
    float fsum=0.0f;
    for(auto x:fA) fsum=fsum+x;
    cout<<"Sum: "<<fsum<<endl;
        //or
        //float sum=0.0f; for (int i=0; i<4; i++) sum=sum+fA[i]; cout<<"Sum: "<<sum<<endl;
    
    //Finding the max Element from an Array
    float fmax=fA[0];
    for(auto x:fA)
    {
        if (x>fmax) fmax=x;
    }
    cout<<"Max: "<<fmax<<endl;
}

#pragma region Function Overloading and Default Argument
//Funktions can have same name but different parameter or datatyp 
// int Add (int x, int y)
// {
//     return x+y;
// }

int Add(int x, int y, int z = 0) // when Argument is assigned with value than it will become default argument
{
    return x+y+z;
}

float Add(float x, float y)
{
    return x+y;
}

//if parameter is same but the return datatyp is different then it will be name conflict
//float add(int x, int y){ } <-- WRONG NAMECONFLIKT
#pragma endregion
#pragma region Function Template
//When the Funktion is the same, and only the Datatyp is different, it's more efficient to use Function Template than write the code for each datatyp
template<class T>
T Max(T x, T y)
{
    if(x>y) return x;
    else return y;
}
#pragma endregion
#pragma region Parameter Passing
//CALL BY VALUE
    void Swap(int a, int b)
    {
                    // Stack -> main -> valA = 10, valB=33;
                    // Stack -> Swap -> a=valA, b=valB, temp;
        cout<<"    Pass by Val|     SWAP before: a = "<<a<<" b = "<<b<<endl;
        int temp;
        temp = a;   // Stack -> Swap -> a=valA, b=valB, temp=valA;
        a = b;      // Stack -> Swap -> a=valB, b=valB, temp=valA;
        b = temp;   // Stack -> Swap -> a=valB, b=valA, temp=valA;
        cout<<"    Pass by Val|     SWAP after: a = "<<a<<" b = "<<b<<endl;
                    // It wont change the Parameter Value in Main
                    // It will only change the Parameter in Swap Funktion
    }
//CALL BY ADDRESS
    void Swap(int *pA, int *pB)
    {
                    // Stack -> main -> valA = 10, valB=33;
                    // Stack -> Swap -> a=&valA, b=&valB, temp;
        cout<<"    Pass by Add|     SWAP before: a = "<<*pA<<" b = "<<*pB<<endl;
        int temp;
        temp = *pA;   // Stack -> Swap -> a=&valA, b=&valB, temp=valA;
        *pA = *pB;    // Stack -> Swap -> a=&valB, b=&valB, temp=valA;
        *pB = temp;   // Stack -> Swap -> a=&valB, *valB=valA, temp=valA;
        cout<<"    Pass by Add|     SWAP after: a = "<<*pA<<" b = "<<*pB<<endl;

    }
//CALL BY REFERENZ
    void SwapByRef(int &a, int &b) // when using Call by Referenz it will also called inLine Funktion
    {
        // It wont create another Funktion in Stack with name SwapByRef
        // But it will be generated also in Main 
                    // Stack -> main -> a = valA = 33, b = valB = 10, temp;
        cout<<"    Pass by Ref|     SWAP before: a = "<<a<<" b = "<<b<<endl;
        int temp;
        temp = a;   // Stack -> main -> a = valA = 33, b = valB = 10, temp = a = 33;
        a = b;      // Stack -> main -> a = valA = 10, b = valB = 10, temp = a = 33;
        b = temp;   // Stack -> main -> a = valA = 10, b = valB = 33, temp = a = 33;
        cout<<"    Pass by Ref|     SWAP after: a = "<<a<<" b = "<<b<<endl;

    }
#pragma endregion
#pragma region Return by Address and Referenz
//RETURN BY ADDRESS
    int* CreateHeapArray(int ArraySize)
    {
        int *pArray = new int[ArraySize];   // Creating pointer that pointing to a integer Array that located in Heap with size of ArraySize
        for(int i=0; i<ArraySize;i++)
        {
            pArray[i]=2*i+1;                  // Asign Value to Array
        }
        cout<<"     Ret by Add| pArray from CreateHeapArray pointing to : "<<pArray<<endl;
        return pArray;                      // Returning the Pointer with Address of Heap Array
    }

//RETURN BY REFERENZ
    int& RetValue(int &a)
    {
                    // Stack -> main -> a = nVal = 10
        a=a+5;      // Stack -> main -> a = nVal = 10+5
        return a;   // This mean that RetValue will act like a variable a = nVal, so it can be assigned with Value;
    }
#pragma endregion
int main(void)
{
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
    system("PAUSE");
    return 0;
}

