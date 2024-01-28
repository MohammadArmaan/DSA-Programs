#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int a = 10;
    int &r = a;

    cout<<a<<endl; //10

    r++; //10 + 1 = 11

    cout<<r<<endl; //11
    cout<<a<<endl; //11


    int b = 30;
    r = b;
    cout<<b<<"\t"<<r<<"\t"<<a; // b = 30 -> r = b; -> r = 30 =  a

    return 0;

}