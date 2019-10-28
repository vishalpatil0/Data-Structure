#include<iostream>
#include<string.h>
using namespace std;
struct student
{
	int marks;
	int roll;
	char attendance[2];
};
void average(struct student s[20], int n)
{
	int avg,sum=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(strcmp(s[i].attendance,"P")==0 || strcmp(s[i].attendance,"p")==0)
		{
			cnt++;
			sum=sum+s[i].marks;
		}
	}
	if(cnt==0)
	{
		cout<<"No one was present for the test so unable to calculate average"<<endl;
	
	}
	else
	{
		avg=sum/cnt;
		cout<<"The average of class is ="<<avg<<endl<<endl;
	}
}
void high_low(struct student s[20], int n,int m)
{
	int h=0;
	int l=m;
	for(int i=0;i<n;i++)
	{
		if(strcmp(s[i].attendance,"P")==0 || strcmp(s[i].attendance,"p")==0)
		{
		if(h<s[i].marks)
		{
			h=s[i].marks;
		}}
	}
	cout<<"\nThe highest marks are ="<<h<<endl;
	for(int i=0;i<n;i++)
	{
		if(strcmp(s[i].attendance,"P")==0 || strcmp(s[i].attendance,"p")==0)
		{
		if(l>s[i].marks)
		{
			l=s[i].marks;
		}}
	}
	cout<<"\nThe lowest marks are ="<<l<<endl;
}
void absent(struct student s[20], int n)
{
	cout<<"\n\nList of student who are absent according to their roll number is as follow"<<endl;
	for(int i=0;i<n;i++)
	{
		if(strcmp(s[i].attendance,"AB")==0 || strcmp(s[i].attendance,"ab")==0)
		{
			cout<<s[i].roll<<endl;
		}
	}
}
void most(struct student s[20], int n)
{
	int i,j,c,m;
	int p=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c=0;
			if(s[i].marks==s[j].marks)
			{
				c++;
				if(p<c)
				{
					m=s[i].marks;
					p=c;
				}
			}
		}
	}
	cout<<"\nMarks scored by most of the student are = "<<m<<endl;
}
int main()
{
	int ch,n,i,max_marks,t1;
	char c;
	cout<<"\nEnter the total number of stuents in a class"<<endl;
	cin>>n;
	struct student s[100];
	cout<<"\nEnter the maximum marks"<<endl;
	cin>>max_marks;
	int highest=max_marks;
	int lowest=0;
	cout<<"\nEnter the detail of test exam"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the enrollment number of student "<<i+1<<endl;
		cin>>s[i].roll;
		cout<<"Enter the the attendace status for given student"<<endl;
		cin>>s[i].attendance;
		if(strcmp(s[i].attendance,"P")==0 || strcmp(s[i].attendance,"p")==0)
		{
			cout<<"Enter the marks of given student"<<endl;
			cin>>t1;
			if(t1>max_marks || t1<0)
			{
				cout<<"Invalide marks"<<endl;
				break;
			}
			else
			{
				s[i].marks=t1;
			}
		}
		else
		{
			s[i].marks=0;
		}
	}
	cout<<"\nThe given information is as follow"<<endl;
	cout<<"***********************************************"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Enroll\tMarks\tAttendance"<<endl;
		cout<<s[i].roll<<"\t"<<s[i].marks<<"\t"<<s[i].attendance<<endl;
	}
	do{
		cout<<"***************************************************************\n\n1-The average marks of class\n2-The highest and lowest marks of class\n3-List of student who were absent for the class\n4-Marks scored by most of the student\n\nEnter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				average(s,n);
				break;
			case 2:
				high_low(s,n,max_marks);
				break;
			case 3:
				absent(s,n);
				break;
			case 4:
				most(s,n);
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
		cout<<"Enter y to continue"<<endl;
		cin>>c;
	}while(c=='Y' || c=='y');
	return 0;
}
