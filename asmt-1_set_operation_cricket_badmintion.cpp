#include<iostream>
#include<string.h>
#define max 10
#define size 20
using namespace std;
int main()
{
	char a[max][size],b[max][size],c[max][size],U[max][size],y; 
	int i,j,k,term,term1,term2,term3,ans,ch;
	int Union(char a[max][size],char b[max][size],char c[max][size],int term1,int term2);
	void display(char a[max][size],char b[max][size],int term1,int term2);
	void intersection(char a[max][size],char b[max][size],int term1,int term2);
	void difference(char a[max][size],char b[max][size],int term1,int term2);
	cout<<"How many elements are their in the universal set"<<endl;
	cin>>term;
	cout<<"Enter the element in universa element"<<endl;
	for(i=0;i<term;i++)
	{
		cin>>U[i];
	}
	cout<<"How many elements play cricket"<<endl;
	cin>>term1;
	cout<<"Enter the element who play cricket"<<endl;
	for(i=0;i<term1;i++)
	{
		cin>>a[i];
	}
	cout<<"How many elements play badminton"<<endl;
	cin>>term2;
	cout<<"Enter the element who play badminton"<<endl;
	for(i=0;i<term2;i++)
	{
		cin>>b[i];
	}
	do{
		cout<<" Main Menu \n1. Set of students who play either cricket or badminton or both\n2. Set of students who play both cricket and badminton\n3. Set of students who play only cricket\n4. Set of students who play only badminton\n5. Set of students who play neither cricket nor badminton\nEnter your choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				display(a,b,term1,term2);
				term3=Union(a,b,c,term1,term2);
				break;
			case 2:
				display(a,b,term1,term2);
				intersection(a,b,term1,term2);
				break;
			case 3:
				display(a,b,term1,term2);
				difference(a,b,term1,term2);
				break;
			case 4:
				display(a,b,term1,term2);
				difference(b,a,term2,term1);
				break;	
			case 5:
				display(a,b,term1,term2);
				difference(U,c,term,term3);
				break;
			default:
				cout<<"invalide choice"<<endl;
		}
		cout<<"\n\nEnter y to continue"<<endl;
		cin>>y;
	}while(y=='y' || y=='Y');
	return 0;
}
void display(char a[max][size],char b[max][size], int term1, int term2)
{
	int i;
	cout<<"\nCricket={";
	for(i=0;i<term1;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<"}";
	cout<<"\nBadminton={";
	for(i=0;i<term2;i++)
	{
		cout<<b[i]<<",";
	}
	cout<<"}";
}
int Union(char a[max][size],char b[max][size],char c[max][size],int term1,int term2)
{
	int i,j,k=0,flag=0,n;
	for(i=0;i<term1;i++)
	{
		strcpy(c[k],a[i]);
		k++;
	}
	for(j=0;j<term2;j++)
	{
		flag=0;
		for(i=0;i<term1;i++)
		{
			if((strcmp(a[i],b[j]))==0)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			strcpy(c[k],b[j]);
			k++;
		}
	}
	n=k;
	cout<<"\nUnion={";
	for(k=0;k<n;k++)
	{
		cout<<c[k]<<",";
	}
	cout<<"}";
	return n;
}
void intersection(char a[max][size],char b[max][size],int term1,int term2)
{
	char c[max][size];
	int i,j,flag=0;
	int k=0,n;
	for(i=0;i<term1;i++)
	{
		flag=1;
		for(j=0;j<term2;j++)
		{
			if((strcmp(a[i],b[j]))==0)
			{
				flag=0;
			}
		}
		if(flag==0)
		{
			strcpy(c[k],a[i]);
			k++;
		}
	}
	n=k;
	cout<<"\nIntersection={";
	for(k=0;k<n;k++)
	{
		cout<<c[k]<<",";
	}
	cout<<"}";
}
void difference(char a[max][size],char b[max][size],int term1,int term2)
{
	char c[max][size];
	int i,j,flag=0;
	int k=0,n;
	for(i=0;i<term1;i++)
	{
		flag=1;
		for(j=0;j<term2;j++)
		{
			if((strcmp(a[i],b[j]))==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			strcpy(c[k],a[i]);
			k++;
		}
	}
	n=k;
	cout<<"\nsDifference={";
	for(k=0;k<n;k++)
	{
		cout<<c[k]<<",";
	}
	cout<<"}";
}	

