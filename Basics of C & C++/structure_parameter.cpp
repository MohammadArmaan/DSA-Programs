#include<iostream>
using namespace std;

//Pass by Value
// struct Rectangle
// {
//     int length;
//     int breadth;
// };

// void func(struct Rectangle r)
// {
//     int area;
//     area = r.length*r.breadth;
//     printf("Area of Rectangle: %d",area);
// }

// int main()
// {
//     struct Rectangle r = {5,10};
//     printf("\n Length: %d\n Breadth: %d\n",r.length,r.breadth);
//     func(r);
//     return 0;
// }

//Pass by Address
// struct Rectangle
// {
//     int length;
//     int breadth;
// };

// void func(struct Rectangle *p)
// {
//     int area;
//     p->length++;
//     p->breadth++;
//     area = p->length*p->breadth;
//     cout<<"Updated Length Value: "<<p->length<<endl<<"Updated Breadth Value"<<p->breadth<<endl;
//     cout<<p->length<<"*"<<p->breadth<<"=";
//     printf(" %d",area);
// }

// int main()
// {
//     struct Rectangle r = {5,10};
//     printf("\n Length: %d\n Breadth: %d\n",r.length,r.breadth);
//     func(&r);
//     return 0;
// }

// Passing Array as the structure as call by value
// struct Test
// {
//     int a[5];
//     int n;
// };

// void func(struct Test *t1, int n)
// {
//     t1->a[0] = 10;
//     t1->a[1] = 20;
//     t1->a[2] = 30;
//     t1->a[3] = 40;
//     t1->a[4] = 50;
//     printf("After getting Updated in the function: \n");
//     for(int i=0; i<n; i++)
//     {
//         printf("%d\n",t1->a[i]);
//     }
// }

// int main()
// {
//     struct Test t1 = {{1,2,3,4,5},5};
//     printf("Before Getting Updated in the function: \n");
//     for(int i=0; i<5; i++)
//     {
//         printf("%d\n",t1.a[i]);
//     }
//     func(&t1, 5);

// }

//Passing Function to the structure
struct Rectangle
{
    int length;
    int breadth;
};

struct Rectangle *func()
{
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 10;
    p->breadth = 20;

    return p;
}

int main()
{
    struct Rectangle *ptr = func();
    cout<<"Length:"<<ptr->length<<"   "<<"Breadth: "<<ptr->breadth<<endl;
    return 0;
}