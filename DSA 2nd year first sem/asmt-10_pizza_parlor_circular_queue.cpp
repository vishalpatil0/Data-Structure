#include<iostream>
using namespace std;

#define size 5
class pizza
{
	public:
		int porder[size];
		int front,rear;
		pizza()
		{
			front=-1;
			rear=-1;
		}
		int qfull()
		{
			if((front==-1 && rear==size-1) || (front==(rear+1)%size))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		int qempty()
		{
			if(front==-1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		void accept_order(int item)
		{
			if(qfull())
			{
				cout<<"\n Very Sorry !!!!! No more orders......\n";
			}
			else
			{
				if(front==-1)
				{
					front=rear=0;
				}
				else
				{
						rear=(rear+10)%size;
				}
				porder[rear]=item;
			}
		}
		void make_payment(int n)
		{
			int item;
			char ans;
			if(qempty())
			{
					cout<<"\n Sorry !!! Order is not there...\n";
			}
			else
			{
				cout<<"Delivered orders are"<<endl;
				for(int i=0; i<n; i++)
		{
			item=porder[front];
			if(front==rear)
			{
				front=rear=-1;
			}
			else
			{
				front=(front+1)%size;
			}
			cout<<"\t"<<item;
		}
		cout<<"\n Total Amount to pay: "<<n*100;
		cout<<"\n Thank you visit Again...";
	}
	}
	
	void order_in_queue()
{
	int temp;
	if(qempty())
	{
		cout<<"\n Sorry !!! There is no pending order...\n";
	}
	else
	{
		temp=front;
		cout<<"\n Pending order as follows... \n";
		while(temp!=rear)
		{
			cout<<"\t"<<porder[temp];
			temp=(temp+1)%size;
		}
		cout<<"\t"<<porder[temp];
	}
}
};
int main()
{
	pizza p1;
	int ch,k,n;
	do
	{
		cout<<"\n\t ***** Welcome To Pizza Parlor *****\n";
		cout<<"\n1.Accept Order \n2.Make A Payment \n3.Pending Orders\n Enter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
					cout<<"\n Which Pizza Do you Like Most...\n";
					cout<<"\n Veg Soya Pizza \n Veg Butter Pizza \n Egg Pizza\n";
					cout<<"\n Please Placed Your Order: ";
					cin>>k;
					p1.accept_order(k);
					break;
			case 2:	
					cout<<"\n How Many Pizza ?";
					cin>>n;
					p1.make_payment(n);
					break;
			case 3:		
					cout<<"\n Following Orders are in a queue to deliver ..... as Follows..\n";
					p1.order_in_queue();
					break;
		}
	}while(ch!=4);
	return 0;
}
