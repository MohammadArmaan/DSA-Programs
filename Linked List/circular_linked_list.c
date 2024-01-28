#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for(i = 1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}


void display(struct Node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    } while (h != head);
    printf("\n");
}

void rdisplay(struct Node *h)
{
    static int flag = 0;
    if(h!=head || flag==0)
    {
        flag = 1;
        printf("%d ",h->data);
        rdisplay(h->next);
    }
    flag = 0;
}

int length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p=p->next;
    } while (p != head);
    return len;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>length(head))
    {
        return;
    }

    if(index == 0)
    {
        t =(struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        if(head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head)
            {
                p = p->next;  
            }
            p->next = t;
            t->next = head;
            head = t;
        } 
    }
    else
    {
        for(i = 0; i<index-1; i++)
        {
            p = p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}


int delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;

    if(index < 0 || index > length(head))
    {
        return -1;
    }
    if(index == 1)
    {
        while(p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if(head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for(i = 0; i < index-2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}



int main()
{
    int A[] = {2, 3, 4, 5, 6};

    create(A,5);
    // insert(head, 2, 10);
    // delete(head,1);

    // rdisplay(head);
    display(head);
    return 0;
}
