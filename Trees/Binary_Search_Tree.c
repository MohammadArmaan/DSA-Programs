#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void insert(int key)
{
    struct Node *t=root;
    struct Node *r, *p;
    if(root == NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t != NULL)
    {
        r = t;
        if(key < t->data)
        {
            t = t->lchild;
        }
        else if(key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild=p->rchild=NULL;

    if(key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void inorder(struct Node *p)
{
    if(p != NULL)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

struct Node* search(int key)
{
    struct Node *t = root;
    while(t != NULL)
    {
        if(key == t->data)
        {
            return t;
        }
        else if(key< t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;

}

struct Node* rinsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if(p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
    {
       p->lchild = rinsert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = rinsert(p->rchild, key);
    }
    return p;
}

int height(struct Node *p)
{   int x, y;
    if(p == NULL)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x>y? x+1: y+1;
}

struct Node* inpre(struct Node *p)
{
    while(p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

struct Node* insucc(struct Node *p)
{
    while(p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

struct Node* delete(struct Node *p, int key)
{
    struct Node *q;
    if(p == NULL)
    {
        return NULL;
    }
    if(p->lchild == NULL && p->rchild == NULL)
    {   
        if(p == root)
        {
            root = NULL;
        }
        free(p);
    }
    if(key < p->data)
    {
        p->lchild = delete(p->lchild, key);
        
    }
    else if(key > p->data)
    {
        p->rchild = delete(p->rchild, key);
    }
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q = inpre(p->lchild);
            p->data = q->data;
            p->lchild = delete(p->lchild, q->data);
        }
        else
        {
            q = inpre(p->rchild);
            p->data = q->data;
            p->rchild = delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    struct Node *temp;

    // insert(10);
    // insert(5);
    // insert(20);
    // insert(8);
    // insert(30);

    // inorder(root);
    // printf("\n");

    root = rinsert(root, 50);
    rinsert(root, 10);
    rinsert(root, 40);
    rinsert(root, 20);
    rinsert(root, 30);

    delete(root, 50);

    inorder(root);
    printf("\n");

    temp=search(20);
    if(temp != NULL)
    {
        printf("Element %d is found \n",temp->data);
    }
    else
    {
        printf("Element was not found\n");
    }   

    return 0;
}