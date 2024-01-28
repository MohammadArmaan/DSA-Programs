#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

// Pass by Value
// int add(int x, int y)
// {
//     int sum;
//     sum = x + y;

//     return sum;
// }

// int main()
// {
//     int a, b, s;
//     a = 10;
//     b = 20;
//     s = add(a,b);
//     printf("%d",s);

//     return 0;
// }


// Pass by Address
// void swap(int *x, int *y)
// {
//     int temp;
//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

// int main()
// {
//     int a, b;
//     a = 10;
//     b = 20;
//     swap(&a,&b);
//     printf("%d \t %d",a , b);
// return 0;
// }

// Pass by Reference
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;

}

int main()
{
    int a, b;
    a = 10;
    b = 20;
    swap(a,b);
    printf("%d \t %d", a, b);

    return 0;
}