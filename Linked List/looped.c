#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void create(int A[], int n)
{
    struct Node *last, *temp;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

int islooped(struct Node *f)
{
    if (f == NULL) {
        return 0; // No loop in an empty list
    }

    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : NULL;

        if (p == q)
        {
            return 1; // There is a loop
        }

    } while (p && q);

    return 0; // No loop
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    create(A, 5);

    struct Node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    printf("Is the Linked List is Looped or not: %d\n", islooped(first));

    return 0;
}
