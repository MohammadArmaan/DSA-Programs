#include<iostream>
#include<stdio.h>

using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

void init(struct Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

int perimeter(struct Rectangle r)
{
    return 2*(r.length + r.breadth);
}

int main()
{
    Rectangle r = {0,0};
    int a, peri, l, b;
    cout<<"Enter the Length and Breadth"<<endl;
    cin>>l>>b;

    init(&r, l, b);

    a = area(r);
    peri = perimeter(r);

    cout<<"The Area of "<<r.length<<" and "<<r.breadth<<" = "<<a<<endl;
    cout<<"The Perimeter of "<<r.length<<" and "<<r.breadth<<" = "<<peri<<endl;

    return 0;
}