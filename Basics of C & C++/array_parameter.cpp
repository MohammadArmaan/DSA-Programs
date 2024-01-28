#include<iostream>
#include<stdio.h>

using namespace std;

// Function to print values of array
// void func(int A[],int n)
// {
//     int i;
//     for(i =0; i<n; i++)
//     {
//         printf("%d\n",A[i]);
//     }
// }

// int main()
// {
//     int a[5] = {1,2,3,4,5};
//     func(a,5);

//     return 0;
// }

// Call by Address
// void func(int A[],int n)
// {
//     A[0]=10;
// }

// int main()
// {
//     int a[5] = {1,2,3,4,5};
//     int  n=5;
//     func(a,n);
//     for(int i = 0; i<n; i++)
//     {
//         printf("%d",a[i]);
//     }

//     return 0;
// }

// Returning as a Array
int * func(int n)
{
    int *p;
    p = new int[n];
    for(int i=0; i<n; i++)
    {
       p[i]=i+1; 
    }

    return p;
}

int main()
{
    int *ptr, a = 5;
    ptr = func(a);

    for(int i=0; i<a; i++)
    {
        printf("%d",ptr[i]);
    }
    return 0;
}