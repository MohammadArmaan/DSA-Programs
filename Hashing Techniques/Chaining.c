#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;

typedef struct HashTable 
{
    Node **HT;
} HashTable;

HashTable *createHashTable() 
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->HT = (Node **)malloc(10 * sizeof(Node *));
    for (int i = 0; i < 10; i++) 
    {
        hashTable->HT[i] = NULL;
    }
    return hashTable;
}

int hash(int key) 
{
    return key % 10;
}

void SortedInsert(Node **H, int x) 
{
    Node *t, *q = NULL, *p = *H;
    t = (Node *)malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL) 
    {
        *H = t;
    } 
    else 
    {
        while (p && p->data < x) 
        {
            q = p;
            p = p->next;
        }

        if (p == *H) 
        {
            t->next = *H;
            *H = t;
        } 
        else 
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

Node *Search(Node *p, int key) 
{
    while (p != NULL) 
    {
        if (key == p->data) 
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void Insert(Node *H[], int key) 
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}

void destroyHashTable(HashTable *hashTable) 
{
    for (int i = 0; i < 10; i++) 
    {
        Node *p = hashTable->HT[i];
        while (hashTable->HT[i]) 
        {
            hashTable->HT[i] = hashTable->HT[i]->next;
            free(p);
            p = hashTable->HT[i];
        }
    }
    free(hashTable->HT);
    free(hashTable);
}

int main() 
{
    int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    int n = sizeof(A) / sizeof(A[0]);
    HashTable *H = createHashTable();

    for (int i = 0; i < n; i++) 
    {
        Insert(H->HT, A[i]);
    }

    printf("Successful Search\n");
    int key = 6;
    Node *result = Search(H->HT[hash(key)], key);
    if (result != NULL) {
        printf("Key: %d, Value: %d\n", key, result->data);
    } else {
        printf("Key not found.\n");
    }

    printf("Unsuccessful Search\n");
    key = 95;
    result = Search(H->HT[hash(key)], key);
    
    if (result != NULL) 
    {
        printf("Key: %d, Value: %d\n", key, result->data);
    }
    else 
    {
        printf("Key not found.\n");
    }

    destroyHashTable(H);

    return 0;
}
