#include<iostream>
#define max 20
using namespace std;
class sort
{
	public:
		float data[max];
		int n;
		sort();
		void getdata();
		void bubble();
		void selection();
		void display();
};
sort::sort()
{
	for(int i=0;i<max;i++)
	{
		data[i]=0;
	}
}
void sort::getdata()
{
	cout<<"Enter the number of student"<<endl;
	cin>>n;
	cout<<"Enter the student's percentage:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>data[i];
	}
}
void sort::bubble()
{
	float temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(data[j]>data[j+1])
			{
				temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
			}
		}
	}
}
void sort::selection()
{
	float temp;
	for(int i=0;i<n;i-=-1)
	{
		for(int j=i;j<n;j-=-1)
		{
			if(data[i]>data[j])
			{
				temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
	}
}
void sort::display()
{
	cout<<"-------------------"<<endl;
	for(int i=n-1;i>=n-5;i--)
	{
		cout<<data[i]<<endl;
	}
}
				
int main()
{
	char y;
	int ans;
	sort s;
	do{
	cout<<"1-bubble sort\n2-selection sort"<<endl;
	cout<<"enter your choice"<<endl;
	cin>>ans;
	switch(ans)
	{
		case 1:
			s.getdata();
			s.bubble();
			s.display();
			break;
		case 2:
			s.getdata();
			s.selection();
			s.display();
			break;
		default:
			cout<<"Invalide choice"<<endl;
	}
	cout<<"enter y to continue"<<endl;
	cin>>y;
	}while(y=='y' || y=='Y');
	return 0;
}
