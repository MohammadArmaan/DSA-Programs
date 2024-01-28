#include<stdio.h>
#include<stdlib.h>


struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r1 = {5,10};

    r1.length = 2;
    r1.breadth = 5;
    printf("Length: %d\n", r1.length);
    printf("Breadth: %d\n", r1.breadth);
    printf("Area: %d\n", r1.length * r1.breadth);
    printf("Size of Bytes: %lu\n",sizeof(r1));


    return 0;
}