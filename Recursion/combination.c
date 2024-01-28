#include<stdio.h>

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }

    else
    {
        return fact(n-1)*n;
    }
}

int ncr(int n, int r)
{
    int num, den;

    num=fact(n);
    den=fact(r)*fact(n-r);

    return num/den;
}

int ncr2(int n, int r)
{
    if(r==0 || n==r)
    {
        return 1;
    }

    else
    {
        return ncr2(n-1,r-1)+ncr2(n-1,r);
    }
}

int main()
{
    int a, b;
    a = 4;
    b = 2;
    printf("nCr using Factorial of %d and %d = %d\n",a,b,ncr(a,b));
    printf("nCr of %d and %d = %d\n",a,b,ncr2(a,b));

    return 0;
}