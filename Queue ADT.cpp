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
        void insert()
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
        void deletion()
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
        cout<<"1-Insetion\n2-Display\n3-Delete\n4-Exit\n\nEnter your choice = ";
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