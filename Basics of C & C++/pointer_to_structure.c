#include<stdio.h>
#include<stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    // struct Rectangle r = {5, 10};
    // struct Rectangle *p = &r;
    // r.length = 7;
    // p->length = 10;

    // printf("%zu \t %zu",*p, r);

    struct Rectangle *p;

    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 10;
    p->breadth = 15;

    printf("%d \t %d", p->length, p->breadth);





    return 0;
}