#include<iostream>

using namespace std;

class Arthemetic
{
    private:
        int a;
        int b;

    public:
        Arthemetic(int a, int b);
        int add();
        int sub();
};
        Arthemetic::Arthemetic(int a, int b)
        {
            this->a = a;
            this->b = b;
        }

        int Arthemetic::add()
        {
            int c;
            c = a+b;
            return c;
        }

        int Arthemetic::sub()
        {
            int c;
            c = a-b;
            return c;
        }

int main()
{
    Arthemetic ar(10,5);
    cout<<"Addition: "<<ar.add()<<endl;
    cout<<"Subtraction: "<<ar.sub()<<endl;

    return 0;
}