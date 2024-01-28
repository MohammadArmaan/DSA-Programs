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

int linear_search(struct Array arr, int key)
{
    int i;
    for(i = 0; i<=arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }
        return -1;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int transposition_linear_search(struct Array *arr, int key)
{
    int i;
    for(i = 0; i<=arr->length; i++)
    {
        if(key == arr->A[i])
        {   
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
    }
        return -1;
}

int move_to_head_linear_search(struct Array *arr, int key)
{
    int i;
    for(i = 0; i<=arr->length; i++)
    {
        if(key == arr->A[i])
        {   
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
        return -1;
}

int main()
{
    struct Array arr={{2,4,6,8,10},10,5};

    // printf("Searched Element's Using Linear Search of Index is: %d\n",linear_search(arr, 8));
    // printf("Searched Element's Using Transposition Linear Search of Index is: %d\n",transposition_linear_search(&arr, 8));
    printf("Searched Element's Using Move To Head Linear Search of Index is: %d\n",move_to_head_linear_search(&arr, 8));
    display(arr);

    return 0;

}