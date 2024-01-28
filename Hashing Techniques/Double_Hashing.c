#include <stdio.h>
#include <string.h>

#define SIZE 10
#define PRIME 7

void print(int *vec, int n, char *s) {
    printf("%s: [", s);
    for (int i = 0; i < n; i++) {
        printf("%d", vec[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int hash(int key) {
    return key % SIZE;
}

int primeHash(int key) {
    return PRIME - (key % PRIME);
}

int doubleHash(int H[], int key) {
    int idx = hash(key);
    int i = 0;
    while (H[(hash(idx) + i * primeHash(idx)) % SIZE] != 0) {
        i++;
    }
    return (idx + i * primeHash(idx)) % SIZE;
}

void insert(int H[], int key) {
    int idx = hash(key);

    if (H[idx] != 0) {
        idx = doubleHash(H, key);
    }
    H[idx] = key;
}

int search(int H[], int key) {
    int idx = hash(key);
    int i = 0;
    while (H[(hash(idx) + i * primeHash(idx)) % SIZE] != key) {
        i++;
        if (H[(hash(idx) + i * primeHash(idx)) % SIZE] == 0) {
            return -1;
        }
    }
    return (hash(idx) + i * primeHash(idx)) % SIZE;
}

int main() {
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A) / sizeof(A[0]);
    print(A, n, "A");

    // Hash Table
    int HT[10] = {0};
    for (int i = 0; i < n; i++) {
        insert(HT, A[i]);
    }
    print(HT, SIZE, "HT");

    int index = search(HT, 25);
    printf("key found at: %d\n", index);

    index = search(HT, 35);
    printf("key found at: %d\n", index);

    return 0;
}
