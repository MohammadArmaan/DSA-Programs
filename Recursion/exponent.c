#include<stdio.h>

int pow1(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return pow1(m,n-1)*m;
    }
}

int pow2(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }

    if(n%2 == 0)
    {
        return pow2(m*m,n/2);
    }

    else
    {
        return m*pow2(m*m,(n-1)/2);
    }
}

int main()
{
    int a, b;
    a = 2; 
    b = 9;
    printf("Using Normal Method The Power of %d to %d = %d\n",a,b,pow1(a,b));
    printf("Using Efficient Method The Power of %d to %d = %d\n",a,b,pow2(a,b));
}