#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
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

void push(char x)
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

char pop()
{
    struct Node *p;
    char x = -1;
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

int isbalanced(char *exp)
{
    int i;
    for(i = 0; exp[i]!= '\0'; i++)
    {
        if(exp[i] == '(' ) //|| exp[i] == '[' || exp[i] == '{'
        {
            push(exp[i]);
        }
        else if(exp[i] == ')' ) //|| exp[i] == '[' || exp[i] == '{'
        {
            if(top == NULL)
            {
                return 0;
            }
            pop();
        }
    }
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{   
    char *exp = "((a+b)*(c-d))";

    printf("Is Expresion or not (1: True, 0: False): %d", isbalanced(exp));

    return 0;
}