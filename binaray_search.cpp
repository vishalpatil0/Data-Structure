#include<iostream>
#define max 100
using namespace std;
int main()
{
	int arr[max],s,low,high,mid,i,n,r,f;
	cout<<"Enter the limit of array"<<endl;
	cin>>n;
	cout<<"Enter the element in array"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"the given  array is"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	cout<<"Enter teh element to search"<<endl;
	cin>>s;
	low=0;
	high=n-1;
	mid=(low+high)/2;
	for(i=0;i<n;i++)
	{
		if(s==arr[mid])
		{
			r=mid+1;
			f=1;
		}
		else if(s>arr[mid])
		{
			low=mid;
			mid=(low+high)/2;
		}
		else if(s<arr[mid])
		{
			high=mid;
			mid=(low+high)/2;
		}
	}
	if(f==1)
	{
		cout<<s<<" element found at "<<r<<endl;
	}
	else
	{
		cout<<s<<" element not found "<<r<<endl;
	}
	return 0;
}
	
