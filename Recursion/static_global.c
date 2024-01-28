#include<stdio.h>

// Returning Phase without using static variables
// int func(int n)
// {
//     if(n>0)
//     {
//         return func(n-1)+n;
//     }

//     return 0;
// }

// int main()
// {
//     int a;
//     a = 5;
//     printf("Value after Recursion: %d",func(a));

//     return 0;
// }

// Returning Phase with using static variable
int func(int n)
{
    static int x = 0;
    if(n>0)
    {
        x++;
        return func(n-1) + x;
    }
    return 0;
}

int main()
{
    int a;
    a = 5;
    printf("Value after Recursion: %d",func(a));

    return 0;
}