#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i = 1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void rdisplay(struct Node *p)
{
    if(p != 0)
    {
        printf("%d ", p->data);
        rdisplay(p->next);
    }
}

void rdisplay2(struct Node *p)
{
    if(p != 0)
    {
        rdisplay2(p->next);
        printf("%d ",p->data);
    }
}

int count(struct Node *p)
{
    int c = 0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

int rcount(struct Node *p)
{
    if(p == 0)
    {
        return 0;
    }
    else
    {
      return rcount(p->next) + 1;  
    }
}

int sum(struct Node *p)
{
    int sum = 0;
    while(p != 0)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int rsum(struct Node *p)
{
    if(p == 0)
    {
        return 0;
    }
    else
    {
        return rsum(p->next) + p->data;
    }
}

int max(struct Node *p)
{
    int max = INT32_MIN;
    while(p != 0)
    {
        if(p->data>max)
        {
            max = p->data;
            
        }
        p=p->next;   
    }
    return max;
}


int rmax(struct Node *p)
{
    int x = 0;
    if(p == 0)
    {
        return INT32_MIN;
    }
    else
    {
        x = rmax(p->next);
        if(x>p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

int rmax2(struct Node *p)
{
    int x = 0;
    if(p == 0)
    {
        return INT32_MIN;
    }
    x = rmax2(p->next);
    return x>p->data ? x : p->data;
}

int min(struct Node *p)
{
    int min = INT32_MAX;
    while(p != 0)
    {
        if(p->data<min)
        {
            min = p->data;
            
        }
        p=p->next;   
    }
    return min;
}

int rmin(struct Node *p)
{
    int x = 0;
    if(p == 0)
    {
        return INT32_MAX;
    }
    x = rmin(p->next);
    return x<p->data ? x : p->data;
}

struct Node* Lsearch(struct Node *p, int key)
{
    while(p != 0)
    {
        if(key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct Node * rLsearch(struct Node *p, int key)
{
    if(p == NULL)
    {
        return NULL;
    }

    if(key == p->data)
    {
        return p;
    }
    return rLsearch(p->next, key);
}

struct Node * Lsearch2(struct Node *p, int key) //Move to Head Operation
{
    struct Node *q = NULL;
    while(p != 0)
    {
       if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if(index < 0 || index > count(p))
    {
        return;
    }
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {
        p = first;
        for(int i = 0; i<index-1; i++)
        {
            p = p->next;
        }


        t->next = p->next;
        p->next = t;

        
    }
}

void sorted_insert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
    {
        first = t;
    }
    else
    {
        while(p && p->data<x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;
    if(index <1 || index > count(p))
    {
        return -1;
    }
    
    if(index == 1)
    {
        q = first;
        x = first->data;
        first=first->next;
        free(q);
        return x;
    }

    else
    {
        for(i = 0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int issorted(struct Node *p)
{
    int x = INT32_MIN;
    while(p != NULL)
    {
        if(p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}



void remove_duplicate(struct Node *p)
{
    struct Node *q = p->next;

    while(q != NULL)
    {
        if(p->data != q->data)
        {
           p = q;
           q = q->next;  
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse(struct Node *p)
{
    int *A;
    struct Node *q = p;
    int i = 0;
    A = (int*)malloc(sizeof(int) * count(p)); 
    while(q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;

    }
    first = q;
}

void rreverse(struct Node *q, struct Node *p)
{
    if(p)
    {
        rreverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void concat(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next = second;
    second = NULL;
}


void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
    {
        last->next = p;
    }

    if (q)
    {
        last->next = q;
    }
}

int islooped(struct Node *f)
{
    if (f == NULL) {
        return 0; 
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
            return 1; 
        }

    } while (p && q);

    return 0; 
}

int main()
{   
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8, 10};

    create2(B,5);
    create(A,5);

    struct Node *temp;


    // struct Node *t1, *t2;
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;


    

    // insert(first,5,11);
    // sorted_insert(first,4);

    // delete(first,3);

    // remove_duplicate(first);

    // reverse(first);
    // reverse2(first);
    // rreverse(NULL,first);

    // concat(first, second);

    // merge(first, second);
    // printf("\nFirst: \n");
    // display(first);
    // printf("\nSecond: \n");
    // display(second);

    // printf("\nMerged Linked List: \n");
    // display(third);

    temp=Lsearch(first, 5);
    // temp=Lsearch2(first, 7);
    // temp=rLsearch(first, 5);
    if(temp)
    {
        printf("Key is found %d\n", temp->data);
    }

    else
    {
        printf("Key is not found\n");
    }

    if(issorted(first))
    {
        printf("Linked List is Sorted\n");
    }
    else
    {
        printf("Linked List is not Sorted\n");
    }
    // rdisplay(first);
    // rdisplay2(first);
    // printf("Length of the Linked List is: %d\n", count(first));
    printf("Length of the Linked List is: %d\n", rcount(first));
    // printf("Sum of the Linked List is: %d\n", sum(first));
    printf("Sum of the Linked List is: %d\n", rsum(first));
    // printf("The Maximum of the Linked List is: %d\n", max(first));
    // printf("The Maximum of the Linked List is: %d\n", rmax(first));
    printf("The Maximum of the Linked List is: %d\n", rmax2(first));
    // printf("The Minimum of the Linked List is: %d\n", min(first));
    printf("The Minimum of the Linked List is: %d\n", rmin(first));
    printf("Is the Linked List is Sorted or not: %d\n", issorted(first));
    // printf("Is the Linked List is Looped or not: %d\n", islooped(first));
    display(first);


    return 0;
}
