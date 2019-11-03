#include<iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
struct node
{
		int num;
		struct node *next;
}*head;
class LL
{
//public:

public:

	struct node *create();
	struct node *insert_head();
	void display(struct node *);
	void insert_after();
	void insert_last();
	node *Delete();
	//void delete_nega();
	//void separate();
	node *Create_sorted();
	node *merge(node *,node *);
	LL(){
		head=NULL;
	}
	~LL()
	{
		node *temp, *temp1;
		temp=head->next;
		delete head;
		while(temp!=NULL)
		{
			temp1=temp->next;
			delete temp;
			temp=temp1;
		}
	}
};
node *LL::create()
{
	node *temp = NULL, *New;
	int val,flag;
	char ans='y';
	flag=TRUE;
	do
	{
		cout<<"\n Enter the number: ";
		cin>>val;
		New = new node;
		if(New==NULL)
			cout<<"\n Memory not allocated";
		New->num=val;
		New->next=NULL;
		if(flag==TRUE)
		{
			head=New;
			temp=head;
			flag=FALSE;
		}
		else
		{
			temp->next=New;
			temp=New;
		}
		cout<<"\n Do you want to enter more numbers?(y/n)";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return head;
}

void LL::display(node *head)
{
	node *p=head;
	if(p==NULL){
		cout<<"\n List is empty";
		return;
	}
	while(p!=NULL){
		cout<<"\n"<<p->num;
		p=p->next;
	}
}

void LL::insert_last()
{
	node *New, *temp;
	New=new node;
	cout<<"\n Enter new value: ";
	cin>>New->num;
	if(head==NULL)
		head=New;
	else
	{
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=New;
		New->next=NULL;
	}
	cout<<"\n Node is inserted";
}

void LL::insert_after()
{
	int key;
	node *temp, *New;
	New=new node;
	cout<<"\n Enter new value: ";
	cin>>New->num;
	if(head==NULL)
		head=New;
	else
	{
		cout<<"\n Enter the value of node after which you want to insert node: ";
		cin>>key;
		temp=head;
		do
		{
			if(temp->num==key)
			{
				New->next=temp->next;
				temp->next=New;
				break;
			}
			else
				temp=temp->next;
		}while(temp!=NULL);
	}
	cout<<"\n Node is inserted";
}

node *LL::insert_head()
{
	node *temp, *New;
	New=new node;
	cout<<"\n Enter new value: ";
	cin>>New->num;
	if(head==NULL)
		head=New;
	else
	{
		temp=head;
		New->next=temp;
		head=New;
	}
	cout<<"\n Node is inserted";
	return head;
}

node *LL::Delete()
{
	node *temp1,*temp, *prev;
	prev=new node;
	temp1=head;
	while(temp1!=NULL)
	{
		if(temp1->num<0)
		{
			temp=head;
			while(temp!=NULL)
			{
				if(temp->num<0)
					break;
				prev=temp;
				temp=temp->next;
			}
			if(temp==NULL)
				cout<<"\n Node not found";
			else
			{
				if(temp==head)
				{
					head=temp->next;
					temp1=head;
				}
				else
				{
					prev->next=temp->next;
					temp1=prev->next;
				}
				delete temp;
				cout<<"\n The node is deleted";
			}
		}
		else
			temp1=temp1->next;
	}
	return head;
}

node *LL::Create_sorted()
{
	node *New, *temp, *head, *prev;
	char ch;
	temp=NULL;
	head=NULL;
	do
	{
		New=new node;
		New->next=NULL;
		cout<<"\n Enter the data";
		cin>>New->num;
		if(head==NULL)
			head=New;
		else
		{
			temp=head;
			prev=NULL;
			while(temp!=NULL)
			{
				if(temp->num<New->num)
				{
					prev=temp;
					temp=temp->next;
				}
				else
					break;
			}
			if(prev==NULL)
			{
				New->next=head;
				head=New;
			}
			else
			{
				New->next=prev->next;
				prev->next=New;
			}
		}
		cout<<"\n Do you want to continue: ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return head;
}

node *LL::merge(struct node *first, struct node* second)
{
	node *third=NULL;
	if(first==NULL)
		return(second);
	else if(second==NULL)
		return(first);
	if(first->num<=second->num)
	{
		third=first;
		third->next=merge(first->next,second);
	}
	else
	{
		third=second;
		third->next=merge(first,second->next);
	}
	return(third);
}

int main()
{
	LL l;
	int ch,ch1;
	char ans='y';
	node *start=NULL;
	node *start1,*start2;
	start1=start2=NULL;
	do
	{
		cout<<"\n 1. Create";
		cout<<"\n 2. Display";
		cout<<"\n 3. Insert number";
		cout<<"\n 4. Delete negative numbers";
		cout<<"\n 5. create two lists and merge into third";
		cout<<"\n 6. Exit";
		cout<<"\n Enter choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1: start=l.create();
		break;
		case 2: l.display(start);
		break;
		case 3: cout<<"\n The list is";
		l.display(start);
		cout<<"\n Menu";
		cout<<"\n 1. Insrt head";
		cout<<"\n 2. Insert after";
		cout<<"\n 3. Insert last";
		cout<<"\n Enter choice: ";
		cin>>ch1;
		switch(ch1)
		{
		case 1: start=l.insert_head();
		break;
		case 2:l.insert_after();
		break;
		case 3:l.insert_last();
		break;
		default:cout<<"\n Invalid choice";
		}
		break;
		case 4:l.Delete();
		break;
		case 5:
			cout<<"\n Enter list of positive numbers";
			start1=l.Create_sorted();
			cout<<"\n Enter list of negative numbers";
			start2=l.Create_sorted();
			cout<<"\n The list of positive numbers:";
			l.display(start1);
			cout<<"\n The list of negative numbers: ";
			l.display(start2);
			start=l.merge(start1,start2);
			cout<<"\n The merged list is....";
			l.display(start);
		}
		cout<<"\n Want to continue: ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return 0;
}
