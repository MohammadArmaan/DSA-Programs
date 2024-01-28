#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter Size: ");
    scanf("%d", &st->size);

    st->top = -1;
    st->S = (int *)malloc(st->size*sizeof(int));
}

void display(struct Stack st)
{
    int i;
    for(i = st.top; i>=0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if(st->top == st->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top - index + 1 < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        x = st.S[st.top - index + 1];
    }
    return x;
}

int stacktop(struct Stack st)
{
    if(st.top == -1)
    {
        return -1;
    }
    else
    {
        return st.S[st.top];
    }
}

int isempty(struct Stack st)
{
    if(st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct Stack st)
{
    if(st.top == st.size-1)
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
    struct Stack st;
    create(&st);
    push(&st, 4);
    push(&st, 5);
    push(&st, 6);
    push(&st, 7);
    push(&st, 8);

    printf("Peeked in Value: %d\n",peek(st, 2));
    printf("Stack Top Value: %d\n",stacktop(st));
    printf("Is Stack Empty or not (1: True, 0: False): %d\n",isempty(st));
    printf("Is Stack Full or not (1: True, 0: False): %d\n",isfull(st));

    // printf("Poped Out or Deleted Element: %d\n", pop(&st));

    display(st);

    return 0;
}