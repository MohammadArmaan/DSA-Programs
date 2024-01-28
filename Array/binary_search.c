#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i; 
    printf("\nElements of the Array are: \n");
    for(i = 0; i<arr.length; i++)
    {
        printf("%d ",arr.A[i]);
    }
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int binary_search(struct Array arr, int key)
{
    int low = 0, mid, high = arr.length-1;
    while(low<=high)
    {   
        mid = (high+low)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }

        else if(key < arr.A[mid])
        { 
            high = mid-1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int RBinary_Search(struct Array arr, int low, int high, int key)
{
    int mid;
    if(low<=high)
    {
        mid = (low + high)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }

        else if(key < arr.A[mid])
        {
            return RBinary_Search(arr,low,mid-1,key);
        }

        else
        {
            return RBinary_Search(arr, mid+1, high, key);
        }

    }
    return -1;
}

int main()
{
    struct Array arr={{2,4,6,8,10},10,5};

    // printf("Searched Element's Using Noraml Binary Search of Index is: %d\n",binary_search(arr, 2));
    printf("Searched Element's Using Recursive Binary Search of Index is: %d\n",RBinary_Search(arr, 0, arr.length, 4));
    display(arr);

    return 0;

}