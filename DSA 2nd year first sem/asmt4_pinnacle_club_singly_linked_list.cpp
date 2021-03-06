#include<iostream>
#include<string.h>
#define size 20
using namespace std;
struct node
{
	int PRN;
	char name[size];
	struct node *next;
}*head;
class sll
{
	public:
		sll();
		struct node *create();
		void display(struct node*);
		void count();
		void reverse(struct node*);
		struct node*insert_President();
		void insert_member();
		void insert_Secretary();
		node*remove();
		node *concat(struct node*,struct node *);
		~sll();
};
sll::sll()
{
	head=NULL;
}
sll::~sll()
{
	node *temp,*temp1;
	temp=head->next;
	delete head;
	while(temp!=NULL)
	{
		temp1=temp->next;
		delete temp;
		temp=temp1;
	}
}
node *sll::create()
{
	node *temp=NULL,*New;
	int val,flag;
	char n[size];
	char ans='y';
	flag=1;
	do
	{
		cout<<"\n Enter the PRN of student: ";
		cin>>val;
		cout<<"\n Enter name: ";
		cin>>n;
		New = new node;
		if(New==NULL)
		{
			cout<<"\n Memory not allocated";
		}
		New->PRN=val;
		strcpy(New->name,n);
		New->next=NULL;
		if(flag==1)
		{
			head=New;
			temp=head;
			flag=0;
		}
		else
		{
			temp->next=New;
			temp=New;
		}
		cout<<"\n Do you want to enter more elements: ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');

	return head;
}
void sll::display(node *head)
{
	struct node*temp;
	temp=head;
	if(temp==NULL)
	{
		cout<<"\n List is empty";
		return;
	}
	while(temp!=NULL)
	{
		cout<<" "<<temp->PRN<<"  "<<temp->name<<"\n";
		temp=temp->next;
	}
}
void sll::count()
{
	struct node*temp;
	int count=0;
	temp=head;
	if(temp==NULL)
	{
		cout<<"\n List is empty";
		return;
	}
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	cout<<"\n Total number of members are "<<count;
}
void sll::reverse(node *head)
{
	if(head!=NULL)
	{
		reverse(head->next);
	}	
	else
	{
		return;
	}
	cout<<" "<<head->PRN<<"  "<<head->name<<"\n";
}
node *sll::remove()
{
	node *temp,*prev;
	int key;
	prev=new node;
	temp=head;
	cout<<"\n Enter the PRN of the node you want to delete: ";
	cin>>key;
	while(temp!=NULL)
	{
		if(temp->PRN==key)
		{
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<"\n Node not found";
	}
	else
	{
		if(temp==head)
		{
			head=temp->next;
		}
		else
		{
			prev->next=temp->next;
		}
		delete temp;
		cout<<"\n The member is deleted";
	}
	return head;
}
void sll::insert_Secretary()
{
	node *New,*temp;
	New=new node;
	cout<<"\n Enter the PRN of the student: ";
	cin>>New->PRN;
	cout<<"\n Enter the name of the student: ";
	cin>>New->name;
	New->next=NULL;
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
	cout<<"\n The member is inserted";
}
void sll::insert_member()
{
	int key;
	node *temp,*New;
	New=new node;
	cout<<"\n Enter the PRN of the student ";
	cin>>New->PRN;
	cout<<"\n Enter the name of the student: ";
	cin>>New->name;
	if(head==NULL)
	{
		head=New;
	}
	else
	{
		cout<<"\n Enter the PRN after which you want to insert the node: ";
		cin>>key;
		temp=head;
		do
		{
			if(temp->PRN==key)
			{
				New->next=temp->next;
				temp->next=New;
				break;
			}
			else
			{
				temp=temp->next;
			}
		}while(temp!=NULL);
	}
	cout<<"\n The member is inserted";
}
node *sll::insert_President()
{
	node *New,*temp;
	New=new node;
	cout<<"\n Enter the PRN of the student ";
	cin>>New->PRN;
	cout<<"\n Enter the name of the student: ";
	cin>>New->name;
	if(head==NULL)
		head=New;
	else
	{
		temp=head;
		New->next=temp;
		head=New;
	}
	cout<<"\n The member is inserted";
	return head;
}
node *sll::concat(node *head1,node *head2)
{
	node *temp;
	temp=head1;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=head2;
	cout<<"\n The lists are concatenated";
	return head1;
}
int main()
{
	sll s;
	int ch,ch1;
	char ans='y';
	node *start=NULL;
	node *start1,*start2;
	start1=NULL;
	start2=NULL;
	do
	{
		cout<<"\n 1. Create.";
		cout<<"\n 2. Display members";
		cout<<"\n 3. Insert member";
		cout<<"\n 4. Delete member";
		cout<<"\n 5. Total number of members of club";
		cout<<"\n 6. Display list in reverse using recursion";
		cout<<"\n 7. Concatenate two lists";
		cout<<"\n 8. Exit";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			start=s.create();
			break;
		case 2:
			s.display(start);
			break;
		case 3:
			cout<<"\n The members are ";
			s.display(start);
			cout<<"\n Menu";
			cout<<"\n 1. Insert President";
			cout<<"\n 2. Insert Member";
			cout<<"\n 3. Insert Secretary";
			cout<<"\n Enter your choice: ";
			cin>>ch1;
			switch(ch1)
			{
			case 1:
				start=s.insert_President();
				break;
			case 2:
				s.insert_member();
				break;
			case 3:
				s.insert_Secretary();
				break;
			}
			break;
			case 4:
				start=s.remove();
				break;
			case 5:
				s.count();
				break;
			case 6:
				s.reverse(start);
				break;
			case 7:
				cout<<"\n Enter the data for first division";
				start1=s.create();
				cout<<"\n Enter the data for second division";
				start2=s.create();
				start=s.concat(start1,start2);
				s.display(start);
				break;
			}
		cout<<"\n Want to continue: ";
		cin>>ans;
		}while(ans=='y'||ans=='Y');
	return 0;
}
