#include<iostream>

using namespace std;

class Diagonal
{   private:
        int n;
        int *A;
    
    public:
        Diagonal()
        {
            n = 2;
            A = new int[2];
        }
        Diagonal(int n)
        {
            this->n = n;
            A = new int[n];

        }
        ~Diagonal()
        {
            delete []A;
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
};

void Diagonal::set( int i, int j, int x)
{
    if(i == j)
    {
        A[i-1] = x;
    }
    
}

int Diagonal::get(int i, int j)
{
    if(i == j)
    {
        return A[i-1];
    }
    else
    {
        return 0;
    }
}

void Diagonal::display()
{
    int i, j;
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(i == j)
            {
                cout<<A[i-1]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    Diagonal d(4);

    d.set(0,0,1);
    d.set(1,1,3);
    d.set(2,2,5);
    d.set(3,3,7);
    d.set(4,4,9);
    cout<<"The Value to be Get is: "<<d.get(2,2)<<endl;
    d.display();
}