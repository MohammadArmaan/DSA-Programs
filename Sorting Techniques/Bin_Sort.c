#include <stdio.h>
#include <stdlib.h>

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

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* CreateNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void Insert(Node** ptrBins, int idx){
    Node* temp = CreateNode(idx);
 
    if (ptrBins[idx] == NULL){ // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
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

void BinSort(int A[], int n){
    int max = Max(A, n);
 
    // Create bins array
    Node** bins = (Node**) malloc((max + 1) * sizeof(Node*));
 
    // Initialize bins array with NULL
    for (int i=0; i<max+1; i++){
        bins[i] = NULL;
    }
 
    // Update count array values based on A values
    for (int i=0; i<n; i++){
        Insert(bins, A[i]);
    }
 
    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (i < max+1){
        while (bins[i] != NULL){
            A[j++] = Delete(bins, i);
        }
        i++;
    }
 
    // Delete heap memory
    free(bins);
}

int main() {
 
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "A");
    BinSort(A, n);
    Print(A, n, "Sorted A");
    printf("\n");
    return 0;
}