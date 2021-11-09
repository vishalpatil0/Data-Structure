#include<iostream>
#include<stdlib.h>
#include<stack>
#include<time.h>
using namespace std;
typedef struct node{
    int data;
    node *next;
    node *previous;
}node;
class LinkedList{
    node *head=NULL,*tail=NULL;
    public:
        LinkedList(){}
        LinkedList(int tpr)
        {
            head=(node *)malloc(sizeof(node));
            head->data=tpr;
            head->next=head;
            head->previous=head;
            tail=head;
        }
        void insert()
        {
            bool check=false;
            node *temp=new node();
            cout<<"1-Insert at first\n2-Insert at last\n3-Insert at certain position\n\nEnter your choice = ";
            int ch;
            cin>>ch;
            switch (ch)
            {
            case 1:
                cout<<"Enter the data = ";
                cin>>temp->data;
                temp->next=head;
                head->previous=temp;
                temp->previous=tail;
                tail->next=temp;
                head=temp;
                temp=NULL;
                delete temp;
                break;
            case 2:
                cout<<"Enter the data = ";
                cin>>temp->data;
                tail->next=temp;
                temp->previous=tail;
                head->previous=temp;
                temp->next=head;
                tail=temp;
                temp=NULL;
                delete temp;
                break;
            case 3:
                cout<<"Enter the data = ";
                cin>>temp->data;
                int pos,count;
                cout<<"Enter the position = ";
                cin>>pos;
                node *travs;
                travs=head;
                count=1;
                while(count!=pos-1)
                {
                    travs=travs->next;
                    if(travs==head)
                    {
                        cout<<"Position is beyond the element's range so element is going to inserted at last location "<<endl;
                        check=true;
                        break;
                    }
                    count++;
                }
                if(check)
                {
                    temp->next=tail->next;
                    tail->next=temp;
                    temp->previous=tail;
                    head->previous=temp;
                    tail=temp;
                }
                else
                {
                    travs->next->previous=temp;
                    temp->next=travs->next;
                    temp->previous=travs;
                    travs->next=temp;
                }
                temp=NULL;
                delete temp;
                break;
            default:
                cout<<"please enter valid choice "<<endl;
                
            }
        }
        void deletion()
        {
            int j;
            cout<<"Enter the element that you want to delete = ";
            cin>>j;
            if(j==head->data)
            {
                node * capture=head;
                head->next->previous=head->previous;
                head->previous->next=head->next;
                head=head->next;
                capture->next,capture->previous=NULL;
                delete capture;
            }
            else
            {
                node *flow=head;
                do
                {
                    if(j==flow->data)
                    {
                        flow->previous->next=flow->next;
                        flow->next->previous=flow->previous;
                        flow->next,flow->previous=NULL;
                        delete flow;
                        cout<<"\n\nElement deleted"<<endl;
                        break;
                    }
                    flow=flow->next;
                }while(flow!=head);
            }
        }
        void display()
        {
            node *flow=head;
            cout<<"\n\nElements are as : \n"<<endl;
            do
            {
                cout<<flow->data<<"->";
                flow=flow->next;
            }while(flow!=head);
            cout<<endl<<endl;
            flow=NULL;
            free(flow);
        }
        void DisplayReverse()
        {
            node *flow=tail;
            cout<<"\n\nElements are as : \n"<<endl;
            do
            {
                cout<<flow->data<<"->";
                flow=flow->previous;
            }while(flow!=tail);
            cout<<endl<<endl;
            flow=NULL;
            free(flow);
        }
        void reverse()
        {
            node *first=NULL,*last;
            node *flow=head;
            stack<int>s;
            do
            {
                s.push(flow->data);
                flow=flow->next;
            }while(flow!=head);
            flow=head;
            do
            {
               if(first==NULL)
               {
                    node *tem=new node;
                    tem->data=s.top();
                    tem->next=tem;
                    tem->previous=tem;
                    first=tem;
                    last=tem;
                    s.pop();
                    tem=NULL;
                    delete tem;
               } 
               else{
                    node *tem=new node;
                    tem->data=s.top();
                    s.pop();
                    tem->next=last->next;
                    tem->previous=last;
                    last->next=tem;
                    last=tem;
                    first->previous=last;
                    tem=NULL;
                    delete tem;
               }
               flow=flow->next;
            }while(flow!=head);
            head=first;
            tail=last;
        }
        void randomallocation()
        {
            cout<<"Enter the range of random elements that you want in the list = "<<endl;
            int length;
            cin>>length;
            srand(time(0));
            while(length!=0)
            {
                node * temp=(node *)malloc(sizeof(node));
                temp->data=rand()%100+1;
                temp->next=tail->next;
                tail->next=temp;
                temp->previous=tail;
                tail=temp;
                length--;
                temp=NULL;
                delete temp;
            }
            tail->next=head;
            head->previous=tail;
        }
};
int main()
{
    cout<<"Enter first element to create first node of linked list = "<<endl;
    int *data=new int;
    cin>>*data;
    LinkedList list(*data);
    int choice;
    delete data;
    while(true)
    {
        cout<<"1-Insert\n2-Display\n3-Display in Reverse Order \n4-Deletion\n5-Reverse\n6-Random Insertion\n7-Exit\n\nEnter your choice = ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            list.insert();
            break;
        case 2:
            list.display();
            break;
        case 3: 
            list.DisplayReverse();
            break;
        case 4:
            list.deletion();
            break;
        case 5:
            list.reverse();
            break;
        case 6:
            list.randomallocation();
            break;
        case 7:
            exit(0);
        default:
            cout<<"Please enter a valid choice"<<endl;
        }
    }
    return 0;
}