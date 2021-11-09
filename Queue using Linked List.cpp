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
        void insert()
        {
            if(front==NULL)
            {
                node *temp=new node;
                cout<<"Enter the element that you want to insert = ";
                cin>>temp->data;
                temp->next=NULL;
                front=back=temp;
                temp=NULL;
                delete temp;
            }
            else
            {
                node *temp=new node;
                cout<<"Enter the element that you want to insert = ";
                cin>>temp->data;
                temp->next=NULL;
                back->next=temp;
                back=temp;
                temp=NULL;
                delete temp;
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
        void deletion()
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
};
int main()
{
    Queue<int> q;
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