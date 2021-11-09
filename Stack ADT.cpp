#include<iostream>
using namespace std;
class stack
{
    int *ptr;
    int size;
    static int top;
    public:
        stack(int size)
        {   
            this->size=size;
            ptr=new int[size];
        }
        void push(int data)
        {
            if(top<=size)
            {
                top++;
                ptr[top]=data;
            }
            else
            {
                cout<<"Stack is full"<<endl;
            }
        }
        void peek()
        {
            int pos;
            cout<<"Enter the position"<<endl;
            cin>>pos;
            cout<<ptr[top-pos+1]<<endl;
        }
        void pop()
        {
            // ptr[top]=NULL;
            if(top!=-1)
            {
            top--;
            }
            else    cout<<"Stack is empty"<<endl;
        }
        void display()
        {
            if(top>=0)
            {
                int flow=top;
                while(flow!=-1)
                {
                    cout<<ptr[flow]<<endl;
                    flow--;
                }
            }
            else
            {
                cout<<"Stack is empty"<<endl;
            }
        }
};
int stack::top=-1;
int main()
{
    stack s(20);
    // s.display();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // s.display();
    // s.pop();
    // s.display();
    s.peek();
    return 0;
}