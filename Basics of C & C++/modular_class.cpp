#include<iostream>
#include<stdio.h>

using namespace std;

class Rectangle
{
    public:
        int length;
        int breadth;

        void init(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area()
        {
            return length *breadth;
        }

        int perimeter()
        {
            return 2*(length + breadth);
        }

};
int main()
{
    Rectangle r ;
    int a, peri, l, b;
    cout<<"Enter the Length and Breadth"<<endl;
    cin>>l>>b;

    r.init(l, b);

    a = r.area();
    peri = r.perimeter();

    cout<<"The Area of "<<r.length<<" and "<<r.breadth<<" = "<<a<<endl;
    cout<<"The Perimeter of "<<r.length<<" and "<<r.breadth<<" = "<<peri<<endl;

    return 0;
}