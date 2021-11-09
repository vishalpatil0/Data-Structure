#include<iostream>
using namespace std;
class Queue
{
    int *ptr;
    int front=-1,rear=-1,size;
    public:
        Queue(int size)
        {
            this->size=size;
            ptr=new int[size];
        }
        void push_back()
        {
            int data;
            cout<<"Enter the element that you want to insert = ";
            cin>>data;
            if((rear+1)%size==front)
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
                    rear=(rear+1)%size;
                    ptr[rear]=data;
                }
            }
        }
        void push_front()
        {
            int data;
            if(front==-1)
            {
                front=rear=0;
                cout<<"\nEnter thed data here = ";
                cin>>data;
                ptr[front]=data;
            }
            else if(front==0 && rear==size-1)
            {
                cout<<"\n\nQueue is full.\n\n"<<endl;
            }
            else if(front==0 && rear!=size-1)
            {
                front=size-1;
                cout<<"\nEnter thed data here = ";
                cin>>data;
                ptr[front]=data;
            }
            else if((front-1)%size == rear)
            {
                cout<<"\n\nQueue is full.\n\n"<<endl;
            }
            else
            {
                front=(front-1)%size;
                cout<<"\nEnter thed data here = ";
                cin>>data;
                ptr[front]=data;
            }
        }
        void display()
        {
            if(front==-1) 
                cout<<"\nQueue is empty.\n"<<endl;
            else
            {
                cout<<endl<<endl<<"Elements are as follow : \n"<<endl;
                int i=front;
                do
                {
                    cout<<ptr[i]<<'|';
                    i=(i+1)%size;
                }while(i!=front);
                cout<<endl<<endl;
            }
        }
        void pop_front()
        {
            if(front==-1)
                cout<<"\nNothing to delete here.\n"<<endl;
            else
            {
                if(front==rear)
                {
                    cout<<endl<<ptr[front]<<" element delted.\n"<<endl;
                    ptr[front]=0;
                    front=rear=-1;
                }
                else
                {
                    cout<<endl<<ptr[front]<<" element delted.\n"<<endl;
                    ptr[front]=0;
                    front=(front+1)%size;
                }
            }
        }
        void pop_back()
        {
            if(front==-1)
                cout<<"\nNothing to delete here.\n"<<endl;
            else
            {
                if(front==rear)
                {
                    cout<<endl<<ptr[front]<<" element delted.\n"<<endl;
                    ptr[front]=0;
                    front=rear=-1;
                }
                else if(rear==0)
                {
                    cout<<endl<<ptr[rear]<<" element delted.\n"<<endl;
                    ptr[rear]=0;
                    rear=size-1;
                }
                else
                {
                    cout<<endl<<ptr[rear]<<" element delted.\n"<<endl;
                    ptr[rear]=0;
                    rear=(rear-1)%size;
                }
            }
        }
};
int main()
{
    Queue q(5);
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