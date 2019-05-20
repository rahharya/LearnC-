#include <iostream>
#include <string>
#include <math.h>
#include "basic.h"
#include "array.h"

using namespace std;

void _85_C11_NewFeatureWithAuto()
{
    float fA[]={3,6.56f,7.345f,6.123f,11.234f,3.86f}; // sometimes we don't need to decleare the size of the Array
    cout<<"New Feature from C11 : auto datatype for Array or Vector"<<endl; cout<<"A[]: ";
    for(auto x:fA) cout<<x<<" "; cout<<endl;//it works like for each, with auto datatyp that means that it will detect the datatyp from A by itself
    // it can also written like this when we already now what datatype that the Array/Vector
    //for(char i:A) cout<<i<<" ";

    //Summe from all Element of the Array
    float fsum=0.0f;
    float fsize=0;
    float faverage;
    for(auto x:fA) 
    {
        fsize+=sizeof(x);
        fsum=fsum+x;
    }
    fsize/=sizeof(fA[0]);
    cout<<"Array Size: "<<fsize<<endl;
    cout<<"Sum       : "<<fsum<<endl;
    faverage=fsum/fsize;
    cout<<"Average   : "<<faverage<<endl;
        //or
        //float sum=0.0f; for (int i=0; i<6; i++) sum=sum+fA[i]; cout<<"Sum: "<<sum<<endl;
    
    //Finding the max Element from an Array
    float fmax=INT32_MIN;
    for(auto x:fA)
    {
        if (x>fmax) fmax=x;
    }
    cout<<"Max       : "<<fmax<<endl;
}
void Section05_CppBasic()
{
    int nNumber;
    cout<<"Enter n: ";
    cin>>nNumber;
    _CE31IsPalindrome(nNumber);
}

void Section08_Array()
{
    _85_C11_NewFeatureWithAuto(); cout<<endl;

    float _fArray[]={3,6.56f,7.345f,6.123f,8.78f,3.56f,1.456f}; //7Element
    int _nArray[]={4,5,7,9,3,12,3,46,58,47,25,31,8,6}; //14 Element
    const float fKey = 1.456f;
    const int nKey=10;
    cout<<"Float Array  : "; for(auto x:_fArray) cout<<x<<" "; cout<<endl;
    _89LinearSearch_SearchKeyInArray(_fArray,7,fKey);

    //Sorting 
    cout<<endl;
    cout<<"Integer Array: "; for(auto x:_nArray) cout<<x<<" "; cout<<endl;
    SortArray(_nArray,14,ACCENDANT);
    cout<<" Sorted Array: "; for(auto x:_nArray) cout<<x<<" "; cout<<endl;
    cout<<"Find key: "<<nKey<<"| in Array"<<endl; _90BinarySearch(_nArray,14,nKey);

    //Drawing Pattern
    _94DrawingPattern1();
    _95DrawingPattern2(4,7);
}

int main(void)
{
    
    return 0;
}

