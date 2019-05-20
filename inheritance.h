#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include "class.h"
using namespace std;


// WHY USING INHERITANCE
//  1. Specilization
    // Adding extra Feature to a Child Class with bringing some Parent Feature in Child Class
    // example: 1. Innova(parent)  <- Fortuner (child) 
    //                  Fortuner extand the Funktion from Innova and both of them is real
    //          2. Rectangle(parent) <- Cube (child)
    // this method is called 'top down' approach. The purpose is to share feature to Child Classes
//  2. Generization
    // Creating virtual Term or general Term in common term or logical Term of a group of Child
    // example: 1. Shape(parent) <- Rectangle (child)
    //                           <- Circle (child)
    //                           <- Triangle (child)
    //                  Shape is general Term of group of Classes (Rectangle, Circle and Triangle)
    //          2. Car (parent) <- Innova(child)
    //                          <- Toyota (child)
    //                          <- Suzuki (child)
    // this method is bottom up approch. The purpose of it is for 'Polymorphism'
// ACCESS SPECIFIER of Inheritance Class
    // Inheritance Class can only Access public and protected Component from Base Class
    // Object that created only have access to public Component
    //
    //                        private | protected | public
    //          inside class |   v    |     v     |   v
    //  inside derived class |   x    |     v     |   v
    //             on object |   x    |     x     |   v

// TYPE OF INHERITANCE
    // Single/ Simple
        //  A          
        //  ^
        //  |
        //  B
    // Hierarchical
        //      A 
        //    / | \
        //   /  |  \
        //  B   C   D
    // Multilevel
        //      A
        //      ^
        //      |
        //      B
        //      ^
        //      |
        //      C
    // Multiple
        //  A      B
        //   \   /
        //     C  
    
// WAYS IF INHERITANCE

class Cube: public HideRectangle
{
    private:
        int height;
    public:
        Cube(int height=1);
        Cube(int length=1, int width=1, int height=1);
        Cube(HideRectangle rect, int height=1);
        ~Cube();
        void setHeight(int height);
        int getHeight();
        int getVolume();
        friend ostream & operator<<(ostream &os, Cube c);
};

Cube::Cube(int height)
{
    setHeight(height);
}

Cube::Cube(int length, int width, int height): HideRectangle(length,width)
{
    setHeight(height);
}

Cube::Cube(HideRectangle rect, int height)
{
    setLength(rect.getLength());
    setWidth(rect.getWidth());
    setHeight(height);
}

Cube::~Cube()
{

}

void Cube::setHeight(int height)
{
    this->height = height;
}

int Cube::getHeight()
{
    return height;
}

int Cube::getVolume()
{
    return area()*getHeight();
}

ostream &operator<<(ostream &os, Cube c)
{
    os<<"l: "<<c.getLength()<<" w: "<<c.getWidth()<<" h: "<<c.getHeight()<<" | A: "<<c.area()<<" V: "<<c.getVolume();
    return os;
}

#endif