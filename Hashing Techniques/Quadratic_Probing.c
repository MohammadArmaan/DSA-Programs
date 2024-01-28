#include<stdio.h>
#define SIZE 10

int hash(int key)
{
   return key%SIZE; 
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while(H[(index + i*i) % SIZE] != 0)
    {
        i++;
    }
    return (index + i*i) % SIZE;
}

void insert(int H[], int key)
{
    int index = hash(key);

    if(H[index] != 0)
    {
        index = probe(H, key);
    }
    H[index] = key;
}

int search(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while(H[(index + i*i) % SIZE]!= key)
    {
        i++;
    }
    return (index + i*i) % SIZE;
}

int main()
{
    int HT[10] = {0};

    insert(HT, 23);
    insert(HT, 43);
    insert(HT, 13);
    insert(HT, 27);

    printf("\n Key Fount at: %d\n", search(HT,13));

    return 0;
}