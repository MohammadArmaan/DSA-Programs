#include<stdio.h>
#include<stdlib.h>

struct Rectangle{
    int length;
    int breadth;
};

int main()
{
    // int a, *p;
    // a=10;
    // p = &a;
    // printf("%d\n",*p);
    // printf("%d %d", p, &a);

    // int *p;
    // int a[5] = {1,2,3,4,5};
    // p=a;
    // for(int i=0; i<5; i++)
    // {
    //     printf("%d",p[i]);
    // }

    // int *p;
    // p= (int*)malloc(5 * sizeof(int));
    // p[0]=5;
    // p[1]=10;
    // p[2]=15;
    // p[3]=20;
    // p[4]=25;

    // for(int i=0; i<5; i++)
    // {
    //     printf("%d\n",p[i]);
    // }

    // free(p);

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    printf("%zu\n",sizeof(p1));
    printf("%zu\n",sizeof(p2));
    printf("%zu\n",sizeof(p3));
    printf("%zu\n",sizeof(p4));
    printf("%zu\n",sizeof(p5));

    return 0;
}