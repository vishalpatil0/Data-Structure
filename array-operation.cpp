#include<iostream>
#define s 100
using namespace std;
int main()
{
	int arr[s],n,i,value,pos,choice,flag,f,cnt;
	char ch;
	cout<<"Enter the limit array"<<"\n";
	cin>>n;
	cout<<"Enter the elements in array"<<"\n";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"The array is "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	do
	{
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"1-insertion \n2-Deletion \n3-Searching\n4-Lenght of array\n5-Display"<<endl<<endl;
	cout<<"Enter you choice "<<endl;
	cin>>choice;
	
	switch(choice)
	{
		case 1:
				cout<<"Enter the element to insert and its position to insert"<<endl;
				cin>>value>>pos;
				for(i=n;i>=pos-1;i--)
				{
					arr[i+1]=arr[i];
				}
				arr[pos-1]=value;
				n++;
				cout<<"Element is inserted"<<endl;
				break;
		case 2:	
				cout<<"Enter the element to element to delete"<<endl;
				cin>>value;
				for(i=0;i<n;i++)
				{
					if(value==arr[i])
					{
						pos=i;
						flag=1;
						break;
					}
				}
				if(flag!=1)
				{
					cout<<"Element not present in array"<<endl;
				}	
				for(i=pos;i<n;i++)
				{
					arr[i]=arr[i+1];
				}
				cout<<"Element is deleted"<<endl;
				n--;
				break;
		case 3:	
				cout<<"Enter the element to element to search"<<endl;
				cin>>value;
				for(i=0;i<n;i++)
				{
					if(value==arr[i])
					{
						pos=i;
						f=1;
						break;
					}
					
				}
				if(f==1)
				{	
					cout<<"Element found at "<<pos+1<<"position"<<endl;
				}
				else
					{
						cout<<"Element not present in array"<<endl;
					}
				break;
		case 4:		cnt=0;
				for(i=0;i<n;i++)
				{
					cnt++;
				}
				cout<<"Lenght of array is "<<cnt<<endl;
				break;
		case 5:
				cout<<"**********************************************"<<endl;
				cout<<"Elements in array"<<"\n";
				for(i=0;i<n;i++)
				{
					cout<<arr[i]<<endl;
				}
				break;
		default:
				cout<<"Invalide choice"<<endl;
				
	}
	
	cout<<"Enter y to continue"<<endl;
	cin>>ch;
	}
	while(ch=='y');
		
	return 0;
}
