#include<iostream>
using namespace std;
template<class T>
class Queue
{
    T *ptr;
    int front=-1,rear=-1,size;
    public:
        Queue(int size)
        {
            this->size=size;
            ptr=new T[size];
        }
        void push_back()
        {
            T data;
            cout<<"Enter the element that you want to insert = ";
            cin>>data;
            if(rear==size-1)
            {
                cout<<"\nQueue is full.\n"<<endl;
            }
            else
            {
                if(front==-1)
                {
                    front++;
                    ptr[front]=data;
                    rear++;
                }
                else
                {
                    ptr[++rear]=data;
                }
            }
        }
        void push_front()
        {
            T data;
            if(rear==size-1 && front==0)
            {
                cout<<"\nQueue is full.\n"<<endl;
            }
            else
            {
               if(front==-1)
                {
                    front++;
                    ptr[front]=data;
                    rear++;
                }
                else
                {
                    if(front==0)
                    {
                        cout<<"\n\nNo space for inserting element at front side.\n"<<endl;
                    }
                    else
                    {
                        front--;
                        cout<<"Enter data that you want to insert at front side = ";
                        cin>>data;
                        ptr[front]=data;
                    }
                } 
            }
        }
        void display()
        {
            if(front==-1 || front>rear) 
                cout<<"\nQueue is empty.\n"<<endl;
            else{
                cout<<endl<<endl<<"Elements are as follow : \n"<<endl;
            for (int i = front; i <=rear ; i++)
            {
                cout<<ptr[i]<<'|';
            } cout<<endl<<endl;
            }
        }
        void pop_front()
        {
            if(front==-1 || front>rear)
                cout<<"\nNothing to delete here.\n"<<endl;
            else
            {
                cout<<endl<<ptr[front++]<<" element delted.\n"<<endl;
                if(front>rear)
                {
                    front=rear=-1;
                }
            }
        }
        void pop_back()
        {
            if(front==-1 || front>rear)
                cout<<"\nNothing to delete here.\n"<<endl;
            else
            {
                cout<<endl<<ptr[rear--]<<" element delted.\n"<<endl;
                if(front>rear)
                {
                    front=rear=-1;
                }
            }
        }
        T Front()
        {
           return ptr[front];
        }
        T Rear()
        {
            return ptr[rear];
        }
};
int main()
{
    Queue<int> q(3);
    while(true)
    {
        cout<<"1-Push Back\n2-Push Front\n3-Display\n4-Pop Front\n5-Pop Back\n6-Exit\n\nEnter your choice = ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:
                    q.push_back();
                    break;
            case 2:
                    q.push_front();
                    break;
            case 3:
                    q.display();
                    break;
            case 4:
                    q.pop_front();
                    break;
            case 5:
                    q.pop_back();
                    break;
            case 6:
                    exit(0);
            default:
                    cout<<"Please enter right choice."<<endl;
        }
    }
    return 0;
}