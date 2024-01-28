#include<iostream>
using namespace std;

class Node

{   public:
        int data;
        Node *next;
};

class Stack
{
    private:
        Node *top;

    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        void display();
        int peek(int index);
        int stacktop();
        int isempty();
        int isfull();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if(t == NULL)
    {
        cout<<"Stack is Full";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if(top == NULL)
    {
        cout<<"Stack is Empty";
    }
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;

}

void Stack::display()
{
    Node *p = top;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int Stack:: peek(int index)
{
    int i;
    Node *p = top;
    for(i = 0; p!=NULL && i<index-1; i++)
    {
        p = p->next;
    }
    if(p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}

int Stack::stacktop()
{
    if(top != NULL)
    {
        return top->data;
    }
    return -1;
}

int Stack::isempty()
{
    return (top!=NULL) ? 0 : 1;
}

int Stack::isfull()
{
    Node *t = new Node;
    int r = (top != NULL) ? 1 : 0;
    delete t;
    return r;
}

int main()
{   
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);

    stk.display();

    // cout<<"The Poped out Element of Stack is: "<<stk.pop()<<endl;

    cout<<"The Peeked Element of Stack is: "<<stk.peek(3)<<endl;
    cout<<"The Top Element of Stack is: "<<stk.stacktop()<<endl;
    cout<<"Is Stack Empty or not (1: True, 0: False): "<<stk.isempty()<<endl;
    cout<<"Is Stack Full or not (1: True, 0: False): "<<stk.isfull()<<endl;


    return 0;
}