#include<stdio.h>
double myPow(double x, int n) {
    if(n == 0)
    {
        return 1;
    }
    
    if(n < 0)
    {
        x = 1/x;
        n = -n;
    }

    if(n%2 == 0)
    {
        double halfpower = myPow(x, n/2);
        return halfpower * halfpower;
    }
    else
    {
        return x * myPow(x, n-1);
    }
    
}
int main()
{
    printf("%f",myPow(2,4));
    return 0;
}