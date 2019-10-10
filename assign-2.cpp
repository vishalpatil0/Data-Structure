#include<iostream>
#define size 100
using namespace std;
struct student
{
	int roll,marks;
	bool p;
}class1[size];
int main()
{
	int n,i,j,p,s,highest=0,lowest=20,avg,sum=0;
	cout<<"Enter the strength of student"<<endl;
	cin>>n;
	cout<<"Enter the student information"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Enter student roll no."<<endl;
		cin>>class1[i].roll;
		cout<<"Enter student marks"<<endl;
		cin>>class1[i].marks;
		cout<<"Enter student presenty status"<<endl;
		cin>>class1[i].p;
	}
	cout<<"Enter datail is as follow"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"Roll NO.\tMarks\t  Presenty"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<class1[i].roll<<"\t\t"<<class1[i].marks<<"\t\t"<<class1[i].p<<endl;
	}
	for(i=0;i<n;i++)
	{
		if(highest<class1[i].marks)
		{
			highest=class1[i].marks;
		}
	}
	cout<<"-------------------------"<<endl;
	cout<<"Highest marks="<<highest<<endl;
	for(i=0;i<n;i++)
	{
		if(lowest>class1[i].marks)
		{
			lowest=class1[i].marks;
		}
	}
	cout<<"-------------------------"<<endl;
	cout<<"Lowest marks="<<lowest<<endl;
	for(i=0;i<n;i++)
	{
		sum+=class1[i].marks;
	}
	avg=sum/n;
	cout<<"-------------------------"<<endl;
	cout<<"Average marks="<<avg<<endl;
	cout<<"The list of student of student who are absent for test are as follow"<<endl;
	for(i=0;i<n;i++)
	{
		if(class1[i].p==false)
		{
			cout<<class1[i].roll<<endl;
		}
	}
	return 0;
}
		
		
