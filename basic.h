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

void _94DrawingPattern1()
{
    int count=1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<count++<<" ";
        }
        cout<<endl;
    }
}

void _95DrawingPattern2(int sorting, int dimension)
{
    for(int i=0;i<dimension;i++)
    {
        for(int j=0;j<dimension;j++)
        {
            if(sorting==1)
            {
                if(j<=i) cout<<"* ";
                else 
                {
                    cout<<endl;
                    break;
                }
            }
            else if(sorting==2)
            {
                if(j<i) cout<<"  ";
                else 
                {
                    cout<<"* ";
                }
            }
            else if(sorting==3)
            {
                
                if(i+j>=dimension-1) cout<<"* ";
                else 
                {
                    cout<<"  ";
                }  
            }
            else
            {
                if(i+j<=dimension-1) cout<<"* ";
                else break;
            }
                                  
        }
        if (sorting>=2)cout<<endl; 
    }
}