#include<stdio.h>

int fib1(int n)
{
    int t0 = 0, t1 = 1, s, i;
    if(n<=1)
    {
        return n;
    }

    else
    {
        for(i = 2; i<=n; i++)
        {
            s = t0 + t1;
            t0 = t1;
            t1 = s;
        }
        return s;
    }
}

int fib2(int n)
{
    if(n<=1)
    {
        return n;
    }

    else
    {
        return fib2(n-2) + fib2(n-1);
    }
}

int F[10];
int fib3(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }

    else
    {
        if(F[n-2]==-1)
        {
            F[n-2]=fib3(n-2);
        }

        if(F[n-1]==-1)
        {
            F[n-1]=fib3(n-1);
        }
        // F[n]=F[n-2]+F[n-1];
        return F[n-2] + F[n-1];
    }
}

int main()
{
    int a;
    a = 7;

    int i;
    for(i=0; i<10; i++)
    {
        F[i]=-1;
    }
    printf("Fibonnaci Series Without using Recursion: %d\n",fib1(a));
    printf("Fibonnaci Series Using Recursion: %d\n",fib2(a));
    printf("Fibonnaci Series using Recursion with Memorization Approach: %d\n",fib3(a));
}