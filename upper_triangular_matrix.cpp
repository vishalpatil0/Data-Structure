#include<iostream>
#define x 100
using namespace std;
int main()
{
	int i,j,r,c,m1[x][x],s=0;
	cout<<"enter the rows and coloumn"<<endl;
	cin>>r>>c;
	cout<<"enter the element in matrix"<<endl;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>m1[i][j];
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(j<i && m1[i][j]!=0)
			{
				s=1;
			}
		}
	}
	if(s==1)
	{
		cout<<"It is upper triangular matrix"<<endl;
	}
	else
	{
		cout<<"fdkfjafjjf";
	}
	return 0;
}
	
