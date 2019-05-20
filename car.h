#include <iostream>
using namespace std;
class Car{
    public:
        void Start(){
            cout<<"Car started"<<endl;
        }
        virtual void Stop(){
            cout<<"Car stopped"<<endl;
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
};