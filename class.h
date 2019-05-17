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
            HideRectangle(int nLength=1, int nWidth=0);
        //3. Deep Copy Constructor
            HideRectangle(HideRectangle &Rect);
    //Property Function
        // Set -> Mutator
            void setLength(int nLength);
            void setWidth(int nWidth);
        // Get -> Accesor
            int getLength();
            int getWidth();
    //Facilitator
        int area();
        int perimeter();
    //Equery
        int isSquare();
    //Destructor
        ~HideRectangle();
};