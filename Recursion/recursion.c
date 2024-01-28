#include<stdio.h>

// Descending Order
// void func1(int n)
// {
//     if(n>0)
//     {
//         printf("%d\t",n);
//         func1(n-1);
//     }
// }

// int main()
// {
//     int x;
//     x = 3;
//     func1(x);

//     return 0;
// }

// Ascending Order
void func1(int n)
{
    if(n>0)
    {
        func1(n-1);
        printf("%d\t",n);
    }
}

int main()
{
    int x;
    x = 3;
    func1(x);

    return 0;
}