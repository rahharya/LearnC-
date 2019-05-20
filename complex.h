#include <iostream>
using namespace std;

class Complex
{
    private:
        int real;
        int img;
    public:
        Complex(int real=0, int img=0);
        
        //both of this is the same
            Complex Subtract(Complex x);
            Complex operator-(Complex x);

        //Friend operator Overloading
            friend Complex operator+(Complex x, Complex y);
        
        void Display();
        //Insertion Operator Overlading
        friend ostream & operator<<(ostream &out, Complex &x);
        
};

Complex::Complex(int real, int img)
{
    this->real=real;
    this->img=img;
}
Complex Complex::Subtract(Complex x)
{
    Complex temp;
    temp.real=real-x.real;
    temp.img=img-x.img;
    return temp;
}
Complex Complex::operator-(Complex x)
{
    Complex temp;
    temp.real=real-x.real;
    temp.img=img-x.img;
    return temp;
}
Complex operator+(Complex x, Complex y)
{
    Complex temp;
    temp.real=x.real+y.real;
    temp.img=x.img+y.real;
    return temp;
}
void Complex::Display()
{
    cout<<real<<"+"<<img<<"i"<<endl;
}
ostream & operator<<(ostream &out, Complex &x)
{
    out<<x.real<<"+i"<<x.img;
    return out;
}
