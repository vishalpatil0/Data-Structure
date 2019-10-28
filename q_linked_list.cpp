#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	string data;
	node *next;
}*front=NULL,*rear=NULL;
void insert()
{
	string n;
	node *temp=new node;
	cout<<"Enter the data to insert"<<endl;
	cin>>n;
	if(front==NULL)
	{
		temp->data=n;
		temp->next=NULL;
		front=rear=temp;
		cout<<n<<" = element inserted"<<endl;
	}
	else
	{
		temp->data=n;
		temp->next=NULL;
		rear->next=temp;
		rear=temp;
		cout<<n<<" = element inserted"<<endl;
	}
}
void display()
{
	if(front==NULL)
	{
		cout<<"Nothing to display here"<<endl;
	}
	else
	{
	node *p=front;
	cout<<"---------------------------------------------------"<<endl;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
	}
}
void Delete()
{
	if(front==NULL)
	{
		cout<<"Nothing to delete here"<<endl;
	}
 	else
 	{
	node *temp=front;
	cout<<front->data<<" = element delted"<<endl;
	front=front->next;
	}
}
int main()
{
	int ch;
	char c;
	do{
	cout<<"\n1-insert\n2-display\n3-delete"<<endl;
	cout<<"\nEnter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			Delete();
			break;
		default:
			cout<<"Invalid choice"<<endl;
	}
	cout<<"\nEnter y to continue"<<endl;
	cin>>c;
	}while(c='y');
	return 0;
}
