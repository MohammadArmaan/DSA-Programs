#include<iostream>

using namespace std;

class Array
{   
    private:
        int *A;
        int size;
        int length;

    public:
        Array()
        {
            size = 10;
            A = new int[10];
            length = 0;

        }

        Array(int sz)
        {
            size=sz;
            length = 0;
            A = new int[size];
        }

        ~Array()
        {
            delete []A;
        }

        void display();
        void insert(int index, int x);
        int sum();
        int Delete(int index);
};

void Array::display()
{
    for(int i = 0; i<length; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Array::insert(int index, int x)
{
    if(index>=0 && index<=length)
    {
        for(int i = length-1; i>=index; i--)
        {
            A[i+1] = A[i];

        }
        A[index] = x;
        length++;
    }
}

int Array::sum()
{
    int total = 0;
    for(int i = 0; i<length; i++)
    {
        total = total + A[i];
    }
    return total;
}

int Array::Delete(int index)
{
    int x = 0;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(int i = index; i<length; i++)
        {
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}

int main()
{
     Array arr(10);

    arr.insert(0,5);
    arr.insert(1,10);
    arr.insert(2,15);

    cout<<arr.sum()<<endl;
    arr.display();
    cout<<arr.Delete(1)<<endl;
    arr.display();

}
