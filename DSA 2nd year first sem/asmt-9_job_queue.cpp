#include<iostream>
#define s 5
using namespace std;
struct queue
{	
	int jq[s];
	int front,rear;
}q;
class jobQ
{
	public:
		jobQ();
		int isFull();
		int isEmpty();
		int insert(int);
		int dele();
		void display();
};
jobQ::jobQ()
{
	q.front=-1;
	q.rear=-1;
}
int jobQ::isFull()
{
	if(q.rear>=s-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int jobQ::isEmpty()
{
	if(q.front==-1 || q.front>q.rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int jobQ::insert(int item)
{
	if(q.front==-1)
	{
		q.front++;
	}
	q.jq[++q.rear]=item;
	return q.rear;
}
int jobQ::dele()
{
	int item=q.jq[q.front];
	q.front++;
	cout<<"delelted= "<<item<<endl;
	return q.front;
}
void jobQ::display()
{
	for(int i=q.front;i<=q.rear;i++)
	{
		cout<<q.jq[i]<<endl;
	}
}
int main()
{
	int ch,item;
	char ans;
	jobQ obj;
	do
	{
		cout<<"\n Main Menu";
		cout<<"\n 1. Add Job";
		cout<<"\n 2. Delete Job";
		cout<<"\n 3. Display Job Queue";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			if(obj.isFull())
				cout<<"\nCan not insert the Job";
			else
			{
				cout<<"\n Enter the job number: ";
				cin>>item;
				obj.insert(item);
			}
			break;
		case 2:
			if(obj.isEmpty())
				cout<<"\n Queue is empty";
			else
			{
				obj.dele();
			}
			break;
		case 3:
			if(obj.isEmpty())
				cout<<"\n Job queue is empty";
			else
				obj.display();
			break;
		default:
			cout<<"\n Wrong choice...";
		}
		cout<<"\n Do you want to continue: ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return 0;
}

	
