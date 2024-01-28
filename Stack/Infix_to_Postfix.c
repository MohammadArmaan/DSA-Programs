#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
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
    int x = -1;
    if (top == NULL)
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
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (top == NULL)
            {
                return 0;
            }
            pop();
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

int isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    return 1;
}

char *infix_to_postfix(char *infix)
{
    char *postfix;
    int i = 0, j = 0;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (top != NULL && precedence(infix[i]) > precedence(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int eval(char *postfix)
{
    int i = 0;
    int x1, x2, r;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isoperand(postfix[i]))
        {   
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2;
                break;

                case '-': r = x1 - x2;
                break;

                case '*': r = x1 * x2;
                break;

                case '/': r = x1 / x2;
                break;
            }
            push(r);
        }

    }
    return top->data;
}
int main()
{
    char *infix = "a+b*c-d/e";
    push('#');

    char *postfix = infix_to_postfix(infix);

    printf("Postfix Expression of the Given Infix Expression is: %s", postfix);



    return 0;
}
