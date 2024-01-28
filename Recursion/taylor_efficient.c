#include<stdio.h>

double e1(int x, int n)
{
    static double s ;
    if(n == 0)
    {
        return s;
    } 

    else
    {
        s=(1+x*s/n);
        return e1(x,n-1);
    }
}

double e2(int x, int n)
{
    double s = 1, num = 1, den = 1;
    int i;

    for(i=1; i<=n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main()
{
    double a, b;
    a = 1;
    b = 10;
    printf("Taylor Series Expansion of %lf and %lf = %lf\n",a,b,e1(a,b));
    printf("Taylor Series Expansion of %lf and %lf = %lf\n",a,b,e2(a,b));
}