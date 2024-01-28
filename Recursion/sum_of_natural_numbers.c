#include<stdio.h>

// Using Recursion
int sum(int n)
{
    if(n == 0)
    {
        return 0;
    }

    else
    {
        return sum(n-1)+n;
    }
}

// Without using Recursion
int isum(int n)
{
    int i, s=0;
    for(i = 1; i<=n; i++)
    {
        s=s+i;

    }
    return s;
}



int main()
{
    int a;
    a = 5;
    printf("Sum of Natural Numbers using Recursion: %d\n",sum(a));
    printf("Sum of Natural Numbers without using Recursion: %d\n",isum(a));

    return 0;
}