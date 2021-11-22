#include<iostream>
#include<stdlib.h>
#include<stack>
#include<time.h>
using namespace std;
typedef struct node{
    int data;
    node *next;
}node;
class LinkedList{
    node *head=NULL,*tail=NULL;
    public:
        LinkedList(){}
        LinkedList(int tpr)
        {
            head=new node;
            head->data=tpr;
            head->next=NULL;
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
                head=temp;
                temp=NULL;
                delete temp;
                break;
            case 2:
                cout<<"Enter the data = ";
                cin>>temp->data;
                tail->next=temp;
                temp->next=NULL;
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
                while(count!=pos)
                {
                    travs=travs->next;
                    if(travs==NULL)
                    {
                        cout<<"Position is beyond the element's range so element is going to inserted at last location "<<endl;
                        check=true;
                        break;
                    }
                    count++;
                }
                if(check)
                {
                    tail->next=temp;
                    temp->next=NULL;
                    tail=temp;
                }
                else
                {
                    temp->next=travs->next;
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
                head=head->next;
                delete capture;
            }
            else
            {
                node *flow=head;
                node *seek;
                
                while(flow!=NULL)
                {
                    if(j==flow->data)
                    {
                        seek->next=flow->next;
                        delete flow;
                        cout<<"\n\nElement deleted"<<endl;
                        break;
                    }
                    seek=flow;
                    flow=flow->next;
                }
            }
        }
        void display(){
            node *flow=head;
            cout<<"\n\nElements are as : \n"<<endl;
            while(flow!=NULL)
            {
                cout<<flow->data<<"->";
                flow=flow->next;
            }
            cout<<endl<<endl;
            flow=NULL;
            free(flow);
        }
        void reverse()
        {
            node *first=NULL,*last;
            node *go=head;
            stack<int>s;
            while(go!=NULL)
            {
                s.push(go->data);
                go=go->next;
            }
            go=head;
            while(go!=NULL)
            {
               if(first==NULL)
               {
                    node *tem=new node;
                    tem->data=s.top();
                    tem->next=NULL;
                    first=tem;
                    last=tem;
                    s.pop();
                    tem=NULL;
                    delete tem;
               } 
               else{
                    node *tem=new node;
                    tem->data=s.top();
                    tem->next=NULL;
                    s.pop();
                    last->next=tem;
                    last=tem;
                    tem=NULL;
                    delete tem;
               }
               go=go->next;
            }
            head=first;
            tail=last;
            
        }
        void reverse_without_using_stack()
        {
            node *prev=NULL, *Next=NULL, *current=head;
            while(current!=NULL)
            {
                Next=current->next;
                current->next=prev;
                prev=current;
                current=Next;
            }
            head=prev;
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
                tail->next=temp;
                temp->next=NULL;
                tail=temp;
                length--;
                temp=NULL;
                delete temp;
            }
            tail->next=NULL;
        }
        void recursiveDisplay(node *trav)
        {
            cout<<trav->data<<"->";
            if(trav->next!=NULL)
            {
                recursiveDisplay(trav->next);
            }
        }
        void rdisplay()
        {
            recursiveDisplay(head);
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
        cout<<"\n1-Insert\n2-Display\n3-Recursive Display\n4-Deletion\n5-Reverse\n6-Reverse without using stack\n7-Random Insertion\n8-Exit\n\nEnter your choice = ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            list.insert();
            break;
        case 2:
            list.rdisplay();
            break;
        case 3:
            list.display();
            break;
        case 4:
            list.deletion();
            break;
        case 5:
            list.reverse();
            break;
        case 6: 
            list.reverse_without_using_stack();
            break;
        case 7:
            list.randomallocation();
            break;
        case 8:
            exit(0);
        default:
            cout<<"Please enter a valid choice"<<endl;
        }
    }
    return 0;
}