#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
    int length;
    int size;
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

int main()
{
    struct Array arr;
    int n, i;
    printf("Enter the Size of the Array: \n");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc(arr.size*sizeof(int));
    arr.length = 0;

    printf("Enter the Length of the Array: \n");
    scanf("%d",&n);

    printf("\nEnter all Elements: \n");
    for(i = 0; i<n; i++)
    {
        scanf("%d",&arr.A[i]);
    }
    arr.length = n;

    display(arr);

    return 0;

}