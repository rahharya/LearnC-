#ifndef CLASS_H
#define CLASS_H

#include <iostream>
using namespace std;

//Abstract Class for Polymorphysm
class Shape
{
    public:
        virtual int area()=0;
        virtual int perimeter()=0;
};

class Rectangle
{
    public:
    //only datamember will occupied memory in Stack Section and Operator wont 
        int length;
        int width;

    //the operator will be saved in Code Section
        int area() 
        {
            return length*width;
        }
        int perimeter() {
            return 2*(length+width);
        }
};

class HideRectangle:public Shape
{
    //only datamember will occupied memory in Stack Section and Operator wont
    private: // directly write and write aren't permissible
        int length;
        int width;

    //the operator will be saved in Code Section
    public:
    //Constructor
        //1. Default Constructor non parameter
            // HideRectangle()
            // {    // It can be optimised with Parameter Constructor with Default Value
            //     length=0;
            //     width=0;
            // }
        //2. Parameter Constructor
            HideRectangle(int length=1, int Width=0);
        //3. Deep Copy Constructor
            HideRectangle(HideRectangle &Rect);
    //Property Function
        // Set -> Mutator
            void setLength(int length);
            void setWidth(int width);
        // Get -> Accesor
            int getLength();
            int getWidth();
    //Facilitator
        int area();
        int perimeter();
        void inLineFunction() {cout<<"InLine called"<<endl;}
        void nonInLineFunction();
        friend ostream & operator<<(ostream &os, HideRectangle &rec);
    //Equery
        bool isSquare();
    //Destructor
        ~HideRectangle();
};

HideRectangle::HideRectangle(int length, int width)
{    //nWidth have Default Value
    setLength(length);
    setWidth(width);
}

HideRectangle::HideRectangle(HideRectangle &Rect)
{   // Why Referenz Rect -> so new Rectangle wont be created 
    // but create ilias from already created Rectangle

    //NOTE: Deep Memory (HEAP) Allocation
        // When in Deep Copy Constructor there are any Dynamic Memory Allocation for an Objet
        // then it wont create a new pointer but also pointing the same Address the Rect is pointing
        // Test
            /*
                private:
                    int size;
                    int *p;
                public:
                Test(int nSize)
                {
                    size=nSize;
                    p = new int[size];
                }
                Test(Test &from)
                {
                    size=from.size;
                    p = from.p;  <<--- WRONG POINTING SAME ADDRESS LIKE 'from'
                    p = new int[size];
                }


            */ 
    length=Rect.length;
    width=Rect.width;
}
void HideRectangle::setLength(int length){
    if(length>=0) this->length=length;
    else this->length=0;
}
void HideRectangle::setWidth(int width){
    if(width>=0) this->width=width;
    else this->width=0;
}
int HideRectangle::getLength(){
    return length;           
} 
int HideRectangle::getWidth(){
    return width;
}
int HideRectangle::area(){
    return length*width;
}
int HideRectangle::perimeter(){
    return 2*(length+width);
}
void HideRectangle::nonInLineFunction(){
    cout<<"nonInLine called"<<endl;
}
ostream & operator<<(ostream &os, HideRectangle &rec)
{
    os<<"l: "<<rec.getLength()<<" w: "<<rec.getWidth()<<" | A: "<<rec.area();
    return os;
}
bool HideRectangle::isSquare()
{
    if (length==width)
    {
        return true;
    }
    else return false;
}
HideRectangle::~HideRectangle()
{

}

class Circle:public Shape
{
    private:
        float radius;
        float diameter;
    public:
        Circle(float radius);
        float GetDiameter();
        int area();
        int perimeter();

}; 

Circle::Circle(float radius){
    this->radius=radius;
    this->diameter=2*radius;
}

float Circle::GetDiameter(){
    return diameter;
}

int Circle::area(){
    return(22*radius*radius/7);
}

int Circle::perimeter(){
    return(22*diameter/7);
}

#endif
