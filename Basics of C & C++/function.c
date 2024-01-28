#include<stdio.h>
#include<stdlib.h>

int add(int x, int y)
{
    int sum;
    sum = x + y;
    return sum;
}

int main()
{
    int a, b, sum;
    a =5;
    b =10;
    sum = add(a,b);
    printf("The Sum is %d",sum);
    return 0;
}