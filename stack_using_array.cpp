#include<iostream>
#define size 40
using namespace std;
int stack[size],top=-1; 
void display()
{
	if(top==-1)
	{ 
		cout<<"Nothing to display here"<<endl;
	}
	else
	{
		int to=top;
	cout<<"----------------------------------"<<endl;
	while(to!=-1)
	{
		cout<<stack[to]<<endl;
		to--;
	}
	}
}
int push(int n)
{
	if(top>size-1)
	{
		cout<<"Stack if full"<<endl;
	}
	else
	{
	top++;
	stack[top]=n;
	cout<<n<<" = element inserted"<<endl;
	}
}
void pop()
{
	if(top==-1)
	{ 
		cout<<"Stack is empty"<<endl;
	}
	else
	{
	int h=stack[top];
	top--;
	cout<<h<<" = element deleted"<<endl;
	}
}	
int main()
{
	int ch,n;
	char c;
	do
	{
	cout<<"1-push\n2-pop\n3-display"<<"\nEnter your choice"<<endl;
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
		default:
			cout<<"Invalide choice"<<endl;
			break;
	}
	cout<<"Enter y to continue"<<endl;
	cin>>c;
	}while(c='y');			
}

	
