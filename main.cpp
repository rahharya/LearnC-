#include <iostream>
#include <string>
#include <math.h>
#include "class.h"
#include "complex.h"
#include "rational.h"

using namespace std;

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
}
int main(void)
{
    
    system("PAUSE");
    return 0;
}

