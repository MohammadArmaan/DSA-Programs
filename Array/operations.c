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

void append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++]=x;
    }
}

void insert(struct Array *arr, int index, int x)
{
    int i;
    if(index>0 && index<=arr->length)
    {
        for(i = arr->length; i>index; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int delete(struct Array *arr, int index)
{
    int i;
    int x = 0;
    if(x>=0 && x<arr->length)
    {
        for(i = index; i<arr->length-1; i++)
        {
            x = arr->A[index];
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
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

int binary_search(struct Array arr, int key)
{
    int low = 0, mid, high = arr.length-1;
    while(low<=high)
    {   
        mid = (high/low)/2;
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

int get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void  set(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index] = x;
    }
}

int max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for(i = 0; i<arr.length; i++)
    {
        if(arr.A[i]>max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for(i = 0; i<arr.length; i++)
    {
        if(arr.A[i]<min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int sum(struct Array arr)
{
    int total = 0, i;
    for(i = 0; i<arr.length; i++)
    {
        total = total + arr.A[i];
    }
    return total;
}

int avg(struct Array arr)
{
    int total = 0, i;
    for(i = 0; i<arr.length; i++)
    {
        total = total + arr.A[i];
    }
    return total/arr.length;
}

void reverse(struct Array *arr)
{
    int *B;
    int i, j;

    B = (int*)malloc(arr->length*sizeof(int));
    for(i=arr->length-1, j=0; i>=0; i--, j++)
    {
        B[j] = arr->A[i];
    }

    for(i = 0; i<arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void reverse2(struct Array *arr)
{
    int i, j;
    for(i=0,j=arr->length-1; i<j; i++, j-- )
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void insertsort(struct Array *arr, int x)
{
    int i = arr->length-1;
    if(arr->length == arr->size)
    {
        return;
    }
    while(arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;

}

int issorted(struct Array arr)
{
    int i;
    for(i = 0; i<arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
        {
            return 0;
        }

    }
    return 1;
}

void rearange(struct Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    while(i < j)
    {
        while(arr->A[i] < 0)
        {
            i++;
        }

        while(arr->A[j] >= 0)
        {
            j--;
        }

        if(i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }

}

struct Array* merge(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(;i<arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i++];
    }

    for(;j<arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j++];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i++];
    }

    for(;j<arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j++];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array* intersection(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array* difference(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i++];
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    // struct Array arr={{2,4,6,8,10},10,5};
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,6,7,15,20},10,5};
    struct Array *arr3;

    // append(&arr,12);
    // insert(&arr, 4, 7);
    // printf("Element Deleted: %d\n",delete(&arr,3));
    // printf("Searched Element's Using Linear Search of Index is: %d\n",linear_search(arr, 8));
    // printf("Searched Element's Using Transposition Linear Search of Index is: %d\n",transposition_linear_search(&arr, 8));
    // printf("Searched Element's Using Move To Head Linear Search of Index is: %d\n",move_to_head_linear_search(&arr, 8));
    // printf("Searched Element's Using Noraml Binary Search of Index is: %d\n",binary_search(arr, 10));
    // printf("Searched Element's Using Recursive Binary Search of Index is: %d\n",RBinary_Search(arr, 0, arr.length, 4));
    // printf("The Element called for Get method is: %d", get(arr,2));
    // set(&arr,2,5);
    // printf("The Element called for Max method is: %d", max(arr));
    // printf("The Element called for Min method is: %d", min(arr));
    // printf("The Sum of Array is: %d", sum(arr));
    // printf("The Average of Array is: %d", avg(arr));
    // reverse(&arr);
    // reverse2(&arr);
    // insertsort(&arr, 7);
    // printf("Is Array Sorted or not: %d",issorted(arr));
    // rearange(&arr);
    // arr3= merge(&arr1, &arr2);
    // arr3= Union(&arr1, &arr2);
    // arr3= intersection(&arr1, &arr2);
    arr3= difference(&arr1, &arr2);
    display(*arr3);
    // display(arr);

    return 0;

}