#include <iostream>

using namespace std;

class Array {
private:
    int *A;
    int size;
public:
    int length;

    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() {
        delete[] A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Diff(Array arr2);
};

void Array::Display() {
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::Append(int x) {
    if (length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index) {
    int x = 0;
    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
    }
    return x;
}

int Array::LinearSearch(int key) {
    for (int i = 0; i < length; i++) {
        if (key == A[i])
            return i;
    }
    return -1;
}

int Array::BinarySearch(int key) {
    int l = 0, mid, h = length - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}
void Array::Set(int index, int x) {
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::Get(int index) {
    if (index >= 0 && index < length)
        return A[index];
    return -1;  // Or some other appropriate value to indicate an error
}

int Array::Max() {
    if (length > 0) {
        int max = A[0];
        for (int i = 1; i < length; i++) {
            if (A[i] > max)
                max = A[i];
        }
        return max;
    }
    return -1;  // Or some other appropriate value to indicate an error
}

int Array::Min() {
    if (length > 0) {
        int min = A[0];
        for (int i = 1; i < length; i++) {
            if (A[i] < min)
                min = A[i];
        }
        return min;
    }
    return -1;  // Or some other appropriate value to indicate an error
}

int Array::Sum() {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += A[i];
    }
    return sum;
}

float Array::Avg() {
    if (length > 0)
        return static_cast<float>(Sum()) / length;
    return -1;  // Or some other appropriate value to indicate an error
}

void Array::Reverse() {
    int* B = new int[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    for (int i = 0; i < length; i++) {
        A[i] = B[i];
    }
    delete[] B;
}



int main() {
    Array* arr1;
    int ch, sz, x, index;

    cout << "Enter Size of Array: ";
    cin >> sz;
    arr1 = new Array(sz);

    do {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter an element and index: ";
                cin >> x >> index;
                arr1->Insert(index, x);
                break;

            case 2:
                cout << "Enter index: ";
                cin >> index;
                x = arr1->Delete(index);
                cout << "Deleted Element is " << x << endl;
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> x;
                index = arr1->LinearSearch(x);
                cout << "Element index " << index << endl;
                break;

            case 4:
                cout << "Sum is " << arr1->Sum() << endl;
                break;

            case 5:
                arr1->Display();
                break;
        }
    } while (ch < 6);

    delete arr1;  // Free the dynamically allocated memory

    return 0;
}
