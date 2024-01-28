#include<iostream>

using namespace std;

class LowerTriangular
{   private:
        int *A;
        int n;
    
    public:
        LowerTriangular()
        {
            n = 2;
            A = new int[2*(2+1)/2];
        }
        LowerTriangular(int n)
        {
            this->n = n;
            A = new int[n*(n+1)/2];

        }
        ~LowerTriangular()
        {
            delete []A;
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        int getDimension(){return n;}
};

void LowerTriangular::set( int i, int j, int x)
{
    if(i >= j)
    {
        // A[i * (i-1)/2 + j - 1] = x;
        A[n* (j-1) - (j-2) * (j-1)/2 + i-j] = x;
    }
    
}

int LowerTriangular::get(int i, int j)
{
    if(i >= j)
    {
        return A[n* (j-1) - (j-2) * (j-1)/2 + i-j];
    }
    else
    {
        return 0;
    }
}

void LowerTriangular::display()
{
    int i, j;
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=n; j++)
        {
            if(i >= j)
            {
                cout<<A[n* (j-1) - (j-2) * (j-1)/2 + i-j]<<" ";
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
{   int d;
    cout<<"Enter Dimensions: ";
    cin>>d;

    LowerTriangular l(d);

    int x;
    cout<<"Enter All Elements: ";
    for(int i = 1; i<=d; i++)
    {
        for(int j = 1; j<=d; j++)
        {
            cin>>x;
            l.set(i, j, x);
        }
    }
    cout<<"\nThe Elements are: "<<endl;
    l.display();



    
}