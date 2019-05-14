#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int _CE30ReversingNumber(int n)
{
    int output=0;
    do
    {
        int r=n%10;
        n/=10;
        output=output*10+r;
    } while (n>0);    
    //cout<<output<<endl;    
    return output;
}

void _CE31IsPalindrome(int n)
{
    int output = _CE30ReversingNumber(n);
    if(n==output) cout<<n<<" palindrome"<<endl;
    else cout<<n<< " not a palindrome"<<endl;
}

void _81GreatestCommonDivider(int a, int b)
{
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }
    cout<<"Greatest Common Divider is "<<a<<endl;
}

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

void _89LinearSearch_SearchKeyInArray(float fInputArray[], int nArraySize, const float key)
{
    bool bKeyFounded= false;
    for(int i=0;i<nArraySize;i++)
    {
        if(fInputArray[i]==key)
        {
            bKeyFounded=true;
            cout<<"Key founded in Array"<<endl;
            break;
        }
    }
    if(!bKeyFounded) cout<<"Key not founded"<<endl;
}

int main(void)
{
    //CE30 and CE31
    /*
        int nNumber;
        cout<<"Enter n: ";
        cin>>nNumber;
        _CE31IsPalindrome(nNumber);
    */
    //81
    _85C11NewFeatureWithAuto();

    float _fArray[]={3,6.56f,7.345f,6.123f,8.78f,3.56f,1.456f};
    const float fKey = 6.0f;
    _89LinearSearch_SearchKeyInArray(_fArray,4,fKey);

    start:
    
    // cout<<"Enter a and b: "; cin>>na>>nb; _81GreatestCommonDivider(na,nb); cout<<endl;
    
    goto start;
    system("PAUSE");
    return 0;
}

