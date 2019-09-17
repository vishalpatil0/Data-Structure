#include<iostream>
#define size 100
using namespace std;
int main()
{
	int arr[size];
	int i,pos,n,value;
	cout<<"Enter the limit of array"<<endl;
	cin>>n;
	cout<<"Enter the element in  array"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the value"<<endl;
	cin>>value;
	cout<<"Enter the position of array"<<endl;
	cin>>pos;
	if(pos>size && pos<=0)
	{
		cout<<"invalid position"<<endl;
	}
	else
	{	
	for(i=n;i>=pos-1;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[pos-1]=value;
	n++;
	cout<<"the resultant array is  array"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	}
	return 0;
}
