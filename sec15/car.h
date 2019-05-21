#include <iostream>
using namespace std;
class Car{
    public:
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