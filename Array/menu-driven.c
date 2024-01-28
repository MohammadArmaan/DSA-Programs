#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElements are: ");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
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

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return x;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l = 0, mid, h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    struct Array arr1;
    int ch, x, index;

    printf("Enter Size of Array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    do
    {
        printf("\n\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an Element and Index: ");
            scanf("%d %d", &x, &index);
            Insert(&arr1, index, x);
            break;

        case 2:
            printf("Enter an Index to be Deleted: ");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("The Deleted Element is %d\n", x);
            break;

        case 3:
            printf("Enter element to be Searched: ");
            scanf("%d", &x);
            index = LinearSearch(&arr1, x);
            printf("Element index is %d\n", index);
            break;

        case 4:
            printf("Sum of Array is %d",sum(arr1));
            break;

        case 5:
            Display(arr1);
            break;
        }
    } while (ch < 6);

    free(arr1.A);

    return 0;
}
