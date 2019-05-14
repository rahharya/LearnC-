#include <iostream>
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