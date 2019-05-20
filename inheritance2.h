#ifndef PARENT_H
#define PARENT_H

class Parent{
    private: int a;
    protected: int b;
    public: int c;
};

class PublicChild : public Parent{
    // All protected and public Element from Parent will be accesible in PublicChild 
    // Protected Member will not accesible in Object
    public:
        void ChildAccesData()
        {
            //a=1; //     error: 'int Parent::a' is private within this context
            b=2;
            c=3;
        }
};

class PublicGrandChild: public PublicChild{
    // All protected and public Element from Parent will be accesible in PublicChild and PublicGrandChild 
    // Protected Member will not accesible in Object
    public:
        void GrandChildAccesData()
        {
            //a=1; //       member "Parent::a" (declared at line 5) is inaccessible (private)
            b=2;
            c=3;
        }
};

class ProtectedChild: protected Parent{
    // All protected and public Element from Parent will become a protected Element in ProtectedChild
    // Member that declared public in Parent will become Protected and cannot be accesable in ProtectedChild-Object
    public:
        void ChildAccesData()
        {
            //a=1;      // member "Parent::a" (declared at line 5) is inaccessible (private)
            b=2;        // protected
            c=3;        // public in Parent -> protected in Child
        }
};

class PublicGrandChild2: public ProtectedChild{
    // All protected and public Element from Parent will become a protected Element in ProtectedChild and PublicGrandChild2
    public:
        void GrandChildAccesData()
        {
            //a=1;        // member "Parent::a" (declared at line 5) is inaccessible (private)
            b=2;          // protected
            c=3;          // protected
        }
};

class PrivateChild: private Parent{
    public:
        void ChildAccesData()
        {
            //a=1;
            b=2;
            c=3;
        }
};

#endif