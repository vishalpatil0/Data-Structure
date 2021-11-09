#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
}*top=NULL;
void display()
{
	if(top==NULL)
	{ 
		cout<<"Nothing to display here"<<endl;
	}
	else
	{
		node *to=top;
	cout<<"----------------------------------"<<endl;
	while(to!=NULL)
	{
		cout<<to->data<<endl;
		to=to->next;
	}
	}
}
void push(int n)
{
	node *temp=new node;
	temp->data=n;
	temp->next=top;
	top=temp;
	cout<<n<<" = element inserted"<<endl;
}
void pop()
{
	if(top==NULL)
	{ 
		cout<<"Stack is empty"<<endl;
	}
	else
	{
	int h=top->data;
	top=top->next;
	cout<<h<<" = element deleted"<<endl;
	}
}	
int peek(int pos)
{
	node *flow=top;
	while(pos!=1)
	{
		flow=flow->next;
		pos--;
	}
	return flow->data;
}
int main()
{
	int ch,n;
	char c;
	do
	{
	cout<<"1-push\n2-pop\n3-display\n4-Peek"<<"\nEnter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter the number to push"<<endl;
			cin>>n;
			push(n);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			cout<<"Enter the position of element = "<<endl;
			cin>>ch;
			cout<<"Element at "<<ch<<" is "<<peek(ch)<<endl;
		default:
			cout<<"Invalide choice"<<endl;
			break;
	}
	cout<<"Enter y to continue"<<endl;
	cin>>c;
	}while(c='y');			
}

	
