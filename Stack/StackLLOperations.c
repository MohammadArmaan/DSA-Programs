#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void display()
{
    struct Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("Stack is Full\n");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *p;
    int x = -1;
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

int peek(int index)
{
    int i;
    struct Node *p = top;
    for(i = 0; p!=NULL && i<index-1; i++)
    {
        p = p->next;
    }
    if(p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}

int stacktop()
{
    if(top != NULL)
    {
        return top->data;
    }
    return -1;
}

int isempty()
{
    return top != NULL ? 0 : 1;
}

int isfull()
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    int r = t != NULL ? 1 : 0;
    free(t);
    return r;
}


int main()
{   
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    // printf("The Poped out Element of Stack is: %d\n",pop());

    printf("The Peeked Element of Stack is: %d\n",peek(3));
    printf("The Top Element of the Stack is: %d\n",stacktop());
    printf("Is Stack Empty or not (1: True, 0: False): %d\n",isempty());
    printf("Is Stack Full or not (1: True, 0: False): %d\n",isfull());




    return 0;
}