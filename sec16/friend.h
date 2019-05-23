#ifndef FRIEND_H
#define FRIEND_H

class Your; // it have to be declared first, because Class Your compiled after Mine class, so Mine Class won't know Your Class

class Mine
{
    private: int a;
    protected: int b;
    public: 
        int c;
        friend Your; // with this method you can access the protected and private method in this friend class
        static int count; // static member of a class belong to a whole Mine Class and not Mine Object so when an Object is created it will share the same static variable
                            // this static variable should be a variable that same through all object from a class 
                            // static member usage
                                // 1. counter
                                // 2. shared memory for all memory
                                // 3. provide information about a class ( ex. Price for a Car)
                            // example 
                            /*
                            Mine c1;
                            c1.count=3;
                            Mine c2;
                            cout<<c2.count<<endl;           //<< also 3
                            */
        Mine(){count++;} 
        static int getCount(){
            // in static funktion we can only acces static variable
            // a++; // ERROR
            return count;
        }
        ~Mine(){count--;}
};

int Mine::count = 0; // to times declaration is needed for static data member

class Your
{
    public:
    Mine m;
    void fun(){
        m.a=10;
        m.b=14;
        m.c=12; // Without friend method only public member can be accessed in another class
    }
    void getA(int &a){
        a=m.a;
    }
    void getB(int &b){ b = m.b; }
    void getC(int &c){ c = m.c; }
};

#endif