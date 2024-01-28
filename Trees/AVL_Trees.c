#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root = NULL;

int nodeheight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int balancefactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

struct Node* LLrotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeheight(p);
    pl->height = nodeheight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}

struct Node* LRrotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeheight(pl);
    p->height = nodeheight(p);
    plr->height = nodeheight(plr);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}

struct Node* RRrotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;
    p->height = nodeheight(p);
    pr->height = nodeheight(pr);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}

struct Node* RLrotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = nodeheight(pr);
    p->height = nodeheight(p);
    prl->height = nodeheight(prl);

    if (root == p)
    {
        root = prl;
    }
    return prl;
}

struct Node* rinsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rinsert(p->rchild, key);
    }
    p->height = nodeheight(p);

    if (balancefactor(p) == 2 && balancefactor(p->lchild) == 1)
    {
        return LLrotation(p);
    }

    else if (balancefactor(p) == 2 && balancefactor(p->lchild) == -1)
    {
        return LRrotation(p);
    }

    else if (balancefactor(p) == -2 && balancefactor(p->rchild) == -1)
    {
        return RRrotation(p);
    }

    else if (balancefactor(p) == -2 && balancefactor(p->rchild) == 1)
    {
        return RLrotation(p);
    }

    return p;
}

void printTree(struct Node *root, int space)
{
    if (root == NULL)
        return;

    space += 5;

    printTree(root->rchild, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->lchild, space);
}

int main()
{
    root = rinsert(root, 50);
    rinsert(root, 10);
    rinsert(root, 20);
    rinsert(root, 5);
    rinsert(root, 30);

    printf("Tree structure:\n");
    printTree(root, 0);

    return 0;
}
