#include<stdio.h>
#include<stdlib.h>

void insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while(i>1 && temp>A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i =1; 
    j= i*2;

    while(j < n-1)
    {
        if(A[j+1] > A[j])
        {
            j = j+1;
        }
        if(A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = j;
            j = 2*j;
        }
        else
        {
            break;
        }
    }
    return val;
}

int main()
{
    int i;
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    for(i=2; i<=7; i++)
    {
        insert(H, i);
    }
    
    printf("Deleted Value is: \n");
    for(i = 7; i >1; i--)
    {
        delete(H,i);
    }

    for(i = 1; i <= 7; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");





    return 0;
}