#include<iostream>

using namespace std;

template<class T>
class Arthemetic
{
    private:
        T a;
        T b;

    public:
        Arthemetic(T a, T b);
        T add();
        T sub();
};

        template<class T>
        Arthemetic<T>::Arthemetic(T a, T b)
        {
            this->a = a;
            this->b = b;
        }

         template<class T>
        T Arthemetic<T>::add()
        {
            T c;
            c = a+b;
            return c;
        }

        template<class T>
        T Arthemetic<T>::sub()
        {
            T c;
            c = a-b;
            return c;
        }

int main()
{
    Arthemetic<float> ar(10.5,5);
    Arthemetic<int> ar1(10,5);
    Arthemetic<char> ar2('A','B');

    cout<<"Addition: "<<ar.add()<<endl;
    cout<<"Subtraction: "<<ar.sub()<<endl;
    cout<<endl;

    cout<<"Addition: "<<ar1.add()<<endl;
    cout<<"Subtraction: "<<ar1.sub()<<endl;
    cout<<endl;

    cout<<"Addition: "<<(int)ar2.add()<<endl;
    cout<<"Subtraction: "<<(int)ar2.sub()<<endl;
    cout<<endl;
    
    return 0;
}