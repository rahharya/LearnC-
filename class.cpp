#include "class.h"

HideRectangle::HideRectangle(int nLength=1, int nWidth=0)
{    //nWidth have Default Value
    setLength(nLength);
    setWidth(nWidth);
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
void HideRectangle::setLength(int nLength){
    if(nLength>=0) length=nLength;
    else length=0;
}
void HideRectangle::setWidth(int nWidth){
    if(nWidth>=0) width=nWidth;
    else width=0;
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

int HideRectangle::isSquare()
{
    return 0;
}

HideRectangle::~HideRectangle()
{

}