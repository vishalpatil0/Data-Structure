#include<iostream>
using namespace std;
#define max 40
int queue[max],rear=-1,front=-1;
void Insert()
{
	int val;
	if(rear==max-1)
	{
		cout<<"overflow"<<endl;
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		cout<<"Enter the value"<<endl;
		cin>>val;
		rear++;
		queue[rear]=val;
		cout<<val<<" = element inserted"<<endl;
	}
}
void Delete()
{
	if(front==-1 && front>rear)
	{
		cout<<"Underflow"<<endl;
	}
	else
	{
		cout<<queue[front]<<" = element deleted"<<endl;
		front++;
	}
}
void Display() 
{
	if (front == - 1)
	{
		cout<<"Queue is empty"<<endl;
	}
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
       {  cout<<queue[i]<<" ";}
      cout<<endl;
   }
}
int main() 
{
   int ch;
   do{
   cout<<"***********************************"<<endl;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
	
   cout<<"Enter your choice : "<<endl;
   cin>>ch;
   switch (ch) {
      case 1: Insert();
         break;
      case 2: Delete();
         break;
      case 3: Display();
         break;
      case 4: cout<<"Exit"<<endl;
         break;
      default: cout<<"Invalid choice"<<endl;
   }
} while(ch!=4);
   return 0;
}
