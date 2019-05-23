#include <iostream>
using namespace std;
class Car{
    public:
        Car()
        {
            cout<<"Car Object created"<<endl;
        }
        virtual ~Car()
        {
            cout<<"Car Object destroyed"<<endl;
        }
    // Pure Virtual Function
    // this class is abstract and muss be overriden by ChildClass
        virtual void Start()=0; // the existence of this Object is virtual
        virtual void Stop()=0;
        virtual void Honk(){
            cout<<"Car honked"<<endl;
        }
};

class Innova: public Car{
    public:
        Innova()
        {
            cout<<"Car: Innova Object created"<<endl;
        }
        ~Innova()
        {
            cout<<"Car: Innova Object destroyed"<<endl;
        }

        void Start(){
            cout<<"Innova started"<<endl;
        }
        void Stop(){
            cout<<"Innova stopped"<<endl;
        }

        virtual void Honk(){
            cout<<"Innova honked"<<endl;
        }
        static int GetPrice(){
            return price;
        }
    private:
        static int price;
};

int Innova::price = 4000;

class Swift: public Car{
    public:
        Swift()
        {
            cout<<"Car: Swift Object created"<<endl;
        }
        ~Swift()
        {
            cout<<"Car: Swift Object destroyed"<<endl;
        }
        void Start(){
            cout<<"Swift started"<<endl;
        }
        void Stop(){
            cout<<"Swift stopped"<<endl;
        }

        virtual void Honk(){
            cout<<"Swift honked"<<endl;
        }
        static int price;
};

int Swift::price = 3800;