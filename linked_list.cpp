#include<iostream>
using namespace std;
struct node 
{
	struct node *next;
	int data;
};
struct node *head=NULL;
struct node *last=NULL;
void insert(int val)
{
	node *temp;
	temp=new node;
	temp->data=val;
	temp->next=head;
	head=temp;
}
void display()
{
	node *temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<endl;
		temp->next=temp;
	}
}
int main()
{
	int ch,val;
	do
	{
	cout<<"1-insert\n2-display"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter value to insert"<<endl;
			cin>>val;
			insert(val);
			break;
		case 2:
			display();
			break;
		default:
			cout<<"invalide choice"<<endl;
	}
	cout<<"enter 1 to continue"<<endl;
	cin>>ch;
	}while(ch);
	return 0;
}

	
		
			
		
		
		
		
		
	 
	
