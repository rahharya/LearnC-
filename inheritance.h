#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include "class.h"
using namespace std;


class Cube: public HideRectangle
{
    private:
        int height;
    public:
        Cube(int length=1, int width=1, int height=1);
        Cube(HideRectangle rect, int height=1);
        void setHeight(int height);
        int getHeight();
        int getVolume();
        friend ostream & operator<<(ostream &os, Cube c);
};

Cube::Cube(int length, int width, int height)
{
    setHeight(height);
    setLength(length);
    setWidth(width);
}

Cube::Cube(HideRectangle rect, int height)
{
    setLength(rect.getLength());
    setWidth(rect.getWidth());
    setHeight(height);
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
    return getLength()*getWidth()*getHeight();
}

ostream &operator<<(ostream &os, Cube c)
{
    os<<"l: "<<c.getLength()<<" w: "<<c.getWidth()<<" h: "<<c.getHeight()<<" | A: "<<c.area()<<" V: "<<c.getVolume();
    return os;
}

#endif