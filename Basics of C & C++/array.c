#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, a[100], i;
    printf("Enter the Size of the Array: ");
    scanf("%d",&n);

    printf("Enter the Array Elements: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Array Elements are: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\n",a[i]);
    }

}