#include<iostream>

using namespace std;

class Rectangle
{
    private: 
        int length;
        int breadth;
    
    public:
        Rectangle()
        {
            length = 0;
            breadth = 0;
        }

        Rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area()
        {
            return length * breadth;
        }

        int perimeter()
        {
            return 2*(length + breadth);
        }

        void setlength(int l)
        {
            length = l;
        }

        int getlength()
        {
            return length;
        }

        void setbreadth(int b)
        {
            breadth = b;
        }

        int getbreadth()
        {
            return breadth;
        }

        ~Rectangle()
        {
            cout<<"Destructor";
        }
};

int main()
{   int l, b;
    cout<<"Enter the Length and Breadth: "<<endl;
    cin>>l>>b;
    Rectangle r(l, b);
    r.setlength(10);
    r.setbreadth(20);
    cout<<"Length: "<<r.getlength()<<endl;
    cout<<"Breadth: "<<r.getbreadth()<<endl;
    cout<<"Area: "<<r.area()<<endl;
    cout<<"Perimeter: "<<r.perimeter()<<endl;

    return 0;

}
