#include<stdio.h>

// Using Recursion
int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }

    else if(n<0)
    {
       return 0;
    }

    else
    {
        return fact(n-1)*n;
    }
}

// Without Using Recursion
int ifact(int n)
{
    int i, s=1;
    if(n == 0)
    {
        return 1;
    }

    else if(n<0)
    {
        return 0;

    }

    else
    {
        for(i = 1; i<=n; i++)
        {
            s=s*i;
        }
        return s;
    }
}


int main()
{
    int a;
    a = 5;
    printf("Factorial of %d = %d\n",a,fact(a));
    printf("Factorial of %d = %d\n",a,ifact(a));

    return 0;
}