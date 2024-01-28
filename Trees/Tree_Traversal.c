#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void stackcreate(struct Stack *st, int size)
{
    st->top = -1;
    st->S = (struct Node **)malloc(size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
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

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isempty(struct Queue *q)
{
    return q->front == q->rear;
}

struct Node *root = NULL;

void treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root Value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isempty(&q))
    {
        p = dequeue(&q);

        printf("Enter Left Child for %d (or -1 to skip): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter Right Child for %d (or -1 to skip): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}


void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void iporeorder(struct Node *p)
{
    if (!p)
        return;

    struct Stack stk;
    stackcreate(&stk, 100);

    while (p || !isempty(&stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void iinorder(struct Node *p)
{
    if (!p)
        return;

    struct Stack stk;
    stackcreate(&stk, 100);

    while (p || !isempty(&stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void ipostorder(struct Node *p)
{
    if (!p)
        return;

    struct Stack stk1, stk2;
    stackcreate(&stk1, 100);
    stackcreate(&stk2, 100);

    push(&stk1, p);

    while (!isempty(&stk1))
    {
        p = pop(&stk1);
        push(&stk2, p);

        if (p->lchild)
            push(&stk1, p->lchild);
        if (p->rchild)
            push(&stk1, p->rchild);
    }

    while (!isempty(&stk2))
    {
        p = pop(&stk2);
        printf("%d ", p->data);
    }
}

void levelorder(struct Node *p)
{
    struct Queue q;
    create(&q,100);

    printf("%d ",root->data);
    enqueue(&q, root);
    while(!isempty(&q))
    {
        root = dequeue(&q);
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int count(struct Node *root)
{
    if(root != NULL)
    {
        return count(root->lchild)+count(root->rchild)+1;
    }
    return 0;
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if(root == NULL)
    {
        return 0;
    }
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
    {
        return x+1;
    }
    else
    {
        return y+1;
    }

}

int main()
{
    treecreate();

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    // printf("Inorder Traversal: ");
    // inorder(root);
    // printf("\n");

    // printf("Postorder Traversal: ");
    // postorder(root);
    // printf("\n");

    // printf("Iterative Preorder Traversal: ");
    // iporeorder(root);
    // printf("\n");

    // printf("Iterative Inorder Traversal: ");
    // iinorder(root);
    // printf("\n");

    // printf("Iterative Postorder Traversal: ");
    // ipostorder(root);
    // printf("\n");

    // printf("Level-Order Traversal: ");
    // levelorder(&root);
    // printf("\n");

    printf("Count of Nodes: %d\n",count(root));
    printf("Height of Tree is: %d\n",height(root));

    return 0;
}
