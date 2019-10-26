#include<iostream>
using namespace std;
struct node
{
	string data;
	node *next;
}*head,*last;
int pos=0;
void display();
void create(string n);
void insert_last(string n);
void insert_first(string n);
void delete_elt(string n);
void insert_anywhere(string n,int pos);
void search(string n);
int main()
{
	char c;
	string n;
	int i,j,x,ch;
	do{
	cout<<"1-create\n2-display\n3-Insert at last\n4-Insert at begining\n5-Insert anywhere\n6-Delete element\n9-Searching"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
		
			cout<<"Enter the data if your creating linked list for first time otherwise it will delete previous linked list"<<endl;
			cin>>n;
			create(n);
	break;
		case 2:
			display();
			break;
		case 3:
			cout<<"Enter data to insert at last position"<<endl;
			cin>>n;
			insert_last(n);
			break;
		case 4:
			cout<<"Enter data to insert at first position"<<endl;
			cin>>n;
			insert_first(n);
			break;
			
		case 5:
			cout<<"Enter data to insert at desired position with position"<<endl;
			cin>>n>>pos;
			insert_anywhere(n,pos);
			break;
		case 6:
			cout<<"Enter element to delete"<<endl;
			cin>>n;
			delete_elt(n);
			break;	
		case 7:
			cout<<"Enter the element to search"<<endl;
			cin>>n;
			search(n);
			break;	
		default:
			cout<<"Invalide choice"<<endl;
	}
	cout<<"Enter y to continue"<<endl;
	cin>>c;
	}while(c=='y');
	return 0;
}
void create(string n)
{	
		if(last==NULL)
		{
			node *temp=new node();
			temp->data=n;
			temp->next=NULL;
			head=last=temp;
			head->next=head;
			last->next=head;
			cout<<"Liked list with ("<<temp->data<<") first node is create"<<endl;
		}
		else
		{
			cout<<"Linked list is already created"<<endl;
		}
}	
void display()
{
	cout<<"-----------------------------------------------"<<endl;
	int i=1;
	if(head==NULL)
	{
		cout<<"Linked list is empty, nothing to display here"<<endl;
	}
	else
	{
		node *temp=head;
		while(temp!=last)
		{
			cout<<i<<"> "<<temp->data<<endl;
			temp=temp->next;
			i++;
		}
		cout<<i<<"> "<<temp->data<<endl;
	}
}	
void insert_last(string n)
{
	if(last==NULL)
	{
		cout<<"Linked list is empty please first create the linked list"<<endl;
	}
	else
	{
		node *temp=new node();
		temp->data=n;
		temp->next=NULL;
		last->next=temp;
		last=temp;
		last->next=head;
		cout<<last->data<<" = element inserted"<<endl;
	}
}
void insert_first(string n)
{
	if(head==NULL)
	{
		cout<<"Linked list is empty please first create the linked list"<<endl;
	}
	else
	{
		node *temp=new node();
		temp->data=n;
		temp->next=head;
		head=temp;
		last->next=head;	
		cout<<head->data<<" = element inserted"<<endl;
	}
}
void insert_anywhere(string n,int pos)
{
	if(head==NULL)
	{
		cout<<"Linked list is empty please first create the linked list"<<endl;
	}
	else
	{
		node *temp=new node();
		node *temp1=head;
		temp->data=n;
		for(int i=1;i<pos-1;i++)
		{
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next=temp;
		cout<<n<<" = element inserted"<<endl;
	}
}
void delete_elt(string n)
{
	if(head==NULL)
	{
		cout<<"Linked list is empty please first create the linked list"<<endl;
	}
	else
	{
		node *temp;
		node *temp1=head;
		if(head==last && head->data==n) //if list has only one element
		{
			temp = head;
		        head=last=NULL;
		        cout<<temp->data<<" = element delted"<<endl;
		        delete(temp);
		}
		if(head->data==n)//first element deletion
		{
			temp=head;
			head=head->next;
			last->next=head;
			cout<<temp->data<<" = element deleted"<<endl;
			delete(temp);
		}
		while(temp1->next!=last)//deletion of in between element 
		{
			if(temp1->next->data==n)
			{
				temp=temp1->next;
				temp1->next=temp->next;
				cout<<temp->data<<" = element deleted"<<endl;
				delete(temp);
			}
			temp1=temp1->next;
		}
		    /*Deletion of last element*/
		if(temp1->next->data==n)    
		{
		        temp=temp1->next;
        		temp1->next=last->next;
       			last = temp1;
       			cout<<temp->data<<" = element deleted"<<endl;
		        delete(temp);
        	}
        	else
        	{
        	
    		cout<<"Element "<<n<<" not found in the list"<<endl;
    		}
			
	}
}
void search(string n)
{
	if(head==NULL)
	{
		cout<<"Linked list is empty please first create the linked list"<<endl;
	}
	else
	{
		node *temp=head;
		int i=1;
		int z=0;
		while(temp->next!=last)
		{
			if(n==temp->data)
			{
				pos=i;
				z=7;
			}
			i++;
			temp=temp->next;
		}
		if(last->data==n)
		{
			cout<<n<<" = element found at last position"<<endl;
		}
		else if(z==7)
		{
			cout<<n<<" element found at "<<pos<<endl;
		}
		else
		{
			cout<<"Element not found"<<endl;
		}
	}
}	
