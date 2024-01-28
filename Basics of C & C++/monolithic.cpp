#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int length, breadth, area, perimeter;
    cout<<"Enter the Length and Breadth"<<endl;
    cin>>length>>breadth;

    area = length * breadth;
    perimeter = 2*(length + breadth);

    cout<<"The Area of "<<length<<" and "<<breadth<<" = "<<area<<endl;
    cout<<"The Perimeter of "<<length<<" and "<<breadth<<" = "<<perimeter<<endl;

    return 0;
}