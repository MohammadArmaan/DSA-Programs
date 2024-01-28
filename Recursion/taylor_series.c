#include<stdio.h>

float e(int x, int n)
{
    static float p = 1, f = 1;
    float r;
    
    if(n == 0)
    {
        return 1;
    }

    else
    {
        r = e(x,n-1);
        p = p*x;
        f = f*n;
        return r + p/f;
    }
}

int main()
{
    float a=1, b=10;
    printf("Taylor Series Sumation for %f and %f = %f",a,b,e(a,b));

    return 0;
}