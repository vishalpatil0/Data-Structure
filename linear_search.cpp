#include<iostream>
#define max 100
using namespace std;
int main()
{
	int n,arr[max],s,i;
	cout<<"Enter the limit of array"<<endl;
	cin>>n;
	cout<<"Enter the element in array"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the element to search in array"<<endl;
	cin>>s;
	int r,f;
	for(i=0;i<n;i++)
	{
		if(s==arr[i])
		{
			r=i+1;
		}	
	}
	cout<<s<<" Element found at "<<r<<" position"<<endl;
	return 0;
}
	
