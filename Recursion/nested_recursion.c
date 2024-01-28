#include<stdio.h>

int func(int n)
{
    if(n>100)
    {
        return n-10;
    }
    else
    {
        return func(func(n+11));
    }
}

int main()
{
    int a;
    a = 95;
    printf("%d ",func(a));

    return 0;
}