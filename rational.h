#include <iostream>
using namespace std;

class Rational
{
    private:
        int p;
        int q;
    public:
    //Constructor
    Rational(int p=0, int q=0);
    Rational(Rational &copy);
    void SetP(int p);
    void SetQ(int q);
    int GetP();
    int GetQ();
    friend Rational operator+(Rational r1, Rational r2);
    friend Rational operator-(Rational r1, Rational r2);
    friend ostream & operator<<(ostream &os, Rational &r);
};

Rational::Rational(int p, int q)
{
    SetP(p);
    SetQ(q);
}

Rational::Rational(Rational &copy)
{
    p=copy.p;
    q=copy.q;
}

void Rational::SetP(int p)
{
    this->p=p;
}

void Rational::SetQ(int q)
{
    this->q=q;
}

int Rational::GetP()
{
    return p;
}

int Rational::GetQ()
{
    return q;
}

Rational operator+(Rational r1, Rational r2)
{
    Rational temp;
    temp.q=r1.q*r2.q;
    temp.p=r1.p*r2.q+r2.p*r1.q;
    return temp;
}

Rational operator-(Rational r1, Rational r2)
{
    Rational temp;
    temp.q=r1.q*r2.q;
    temp.p=r1.p*r2.q-r2.p*r1.q;
    return temp;
}

ostream & operator<<(ostream &os, Rational &r)
{
    os<<r.p<<"/"<<r.q;
    return os;
}

