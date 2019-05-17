#include <iostream>
using namespace std;

class Rectangle
{
    //only datamember will occupied memory in Stack Section and Operator wont
    public: 
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

class HideRectangle
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
    //Equery
        int isSquare();
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
int HideRectangle::isSquare()
{
    return 0;
}
HideRectangle::~HideRectangle()
{

}
