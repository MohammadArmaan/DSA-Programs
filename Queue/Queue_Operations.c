#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if(q->rear == q->size - 1)
    {
        printf("Queue is Full");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if(q->front == q->rear)
    {
        printf("Queue os Empty");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    for(int i = q.front + 1; i<=q.rear; i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int isempty(struct Queue *q)
{
    if(q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

int isfull(struct Queue *q)
{
    if(q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int main()
{   
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(q);

    // printf("The Dequeued Element is: %d\n",dequeue(&q));
    printf("Is Queue Empty or not (1: True, 0: False): %d\n",isempty(&q));
    printf("Is Queue Full or not (1: True, 0: False): %d\n",isfull(&q));

    return 0;
}