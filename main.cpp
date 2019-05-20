#include <iostream>
#include <string>
#include <math.h>
#include "funktionsect.h"
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

int main(void)
{

    system("PAUSE");
    return 0;
}

