#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void Print(int* vec, int n, char* s){
    printf("%s: [", s);
    for (int i=0; i<n; i++){
        printf("%d", vec[i]);
        if (i < n-1){
            printf(", ");
        }
    }
    printf("]\n");
}

int Max(int A[], int n){
    int max = -32768;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int countDigits(int x){
    int count = 0;
    while (x != 0){
        x = x / 10;
        count++;
    }
    return count;
}

void initializeBins(Node** p, int n){
    for (int i=0; i<n; i++){
        p[i] = NULL;
    }
}

Node* CreateNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void Insert(Node** ptrBins, int value, int idx){
    Node* temp = CreateNode(value);
 
    if (ptrBins[idx] == NULL){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        Node* p = ptrBins[idx];
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    free(p);
    return x;
}

int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}

void RadixSort(int A[], int n){
    int max = Max(A, n);
    int nPass = countDigits(max);
 
    // Create bins array
    Node** bins = (Node**) malloc(10 * sizeof(Node*));
 
    // Initialize bins array with NULL
    initializeBins(bins, 10);
 
    // Update bins and A for nPass times
    for (int pass=0; pass<nPass; pass++){
 
        // Update bins based on A values
        for (int i=0; i<n; i++){
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
 
        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10){
            while (bins[i] != NULL){
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        // Initialize bins with NULL again
        initializeBins(bins, 10);
    }
 
    // Delete heap memory
    free(bins);
}


int main() {
 
    int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "A");
    RadixSort(A, n);
    Print(A, n, "Sorted A");
 
    return 0;
}