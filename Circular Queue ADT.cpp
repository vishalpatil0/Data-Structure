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
        void insert()
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
        void deletion()
        {
            if(front==-1)
                cout<<"\nNothing to delete here.\n"<<endl;
            else
            {
                if(front==rear)
                {
                    cout<<endl<<ptr[front]<<" element delted.\n"<<endl;
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
};
int main()
{
    Queue q(5);
    while(true)
    {
        cout<<"1-Insertion\n2-Display\n3-Delete\n4-Exit\n\nEnter your choice = ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:
                    q.insert();
                    break;
            case 2:
                    q.display();
                    break;
            case 3:
                    q.deletion();
                    break;
            case 4:
                    exit(0);
            default:
                    cout<<"Please enter right choice."<<endl;
        }
    }
    return 0;
}