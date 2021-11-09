#include<iostream>
using namespace std;
template<class T>
class Queue
{
        class node
        {
            public:
            T data;
            node *next;
        }*front=NULL,*back=NULL;
    public:
        node * newNode()
        {
            node *temp=new node;
            cout<<"Enter the element that you want to insert = ";
            cin>>temp->data;
            temp->next=NULL;
            return temp;
        }
        void push_back()
        {
            if(front==NULL)
            {
                front=back=newNode();    
            }
            else
            {
                back->next=newNode();
                back=back->next;
            }
        }
        void push_front()
        {
            if(front==NULL)
            {
                back=front=newNode();
            }
            else
            {
                node *p=newNode();
                p->next=front;
                front=p;
                p=NULL;
                delete p;
            }
        }
        void display()
        {
            if(front==NULL)
            {
                cout<<"\n\nThe list is empty."<<endl;
            }
            else
            {
                cout<<"\n\nElements are as follow "<<endl<<endl;
                node *traversal=front;
                while(traversal!=NULL)
                {
                    cout<<traversal->data<<'|';
                    traversal=traversal->next;
                }
                cout<<endl<<endl;
            }
        }
        void pop_front()
        {
            if(front==NULL)
            {
                cout<<"\nNothing to delete here.\n\n";
            }
            else
            {
                if(front==back)
                {
                    cout<<"\n\n"<<front->data<<" element got deleted.\n\n";
                    node *temp=front;
                    delete temp;
                    front=back=NULL;
                }
                else
                {
                    cout<<"\n\n"<<front->data<<" element got deleted.\n\n";
                    node *temp=front;
                    front=front->next;
                    delete temp;
                }
            }
        }
        void pop_back()
        {
            if(front==NULL)
            {
                cout<<"\nNothing to delete here.\n\n";
            }
            else
            {
                if(front==back)
                {
                    cout<<"\n\n"<<front->data<<" element got deleted.\n\n";
                    node *temp=front;
                    delete temp;
                    front=back=NULL;
                }
                else
                {
                    node *trav=front;
                    while(trav->next!=back)
                    {
                        trav=trav->next;
                    }
                    cout<<"\n\n"<<back->data<<" element got deleted.\n\n";
                    back=trav;
                    trav=trav->next;
                    delete trav;
                    back->next=NULL;
                }
            }
        }
};
int main()
{
    Queue<int> q;
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