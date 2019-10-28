#include<iostream>
#define max 10
using namespace std;
int main()
{
	int a[max][max],b[max][max],c[max][max];
	int r1,r2,c1,c2,i,j,ch,primary=0,secondary=0;
	bool isupper=true;
	char g;
	cout<<"Enter the rows and coloumn for matrix A"<<endl;
	cin>>r1>>c1;
	cout<<"Enter the element of matrix A"<<endl;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			cin>>a[i][j];
		}
	}
	do{
	cout<<"1-Check upper triangular or not matrix A\n2-summation of diagonals of matrix A\n3-Transpose of matrix A\n4-Addition\n5-subtract\n6-Multiplication"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			for(i=0;i<r1;i++)
			{
				for(j=0;j<i;j++)
				{
					if(a[i][j]!=0)
					{
						isupper=false;
						break;
					}
				}
			}
			if(isupper==true)
			{
				cout<<"The given matrix is upper triangular"<<endl;
			}
			else
			{
				cout<<"This is not upper triangular"<<endl;
			}
			break;
		case 2:
			if(r1==c1)
			{
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
				{
					if(i==j)
					{
						primary+=a[i][j];
					}
					if((i+j)==(r1-1))
					{
						secondary+=a[i][j];
					}
				}
			}
			cout<<"Primary diagonal sum is ="<<primary<<endl<<"Secondary diagonal sum is = "<<secondary<<endl;
			}
			else
			{
				cout<<"Rows and coloumn must be same for summation of diagonals"<<endl;
			}	
			break;	
		case 3:
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
				{
					c[i][j]=a[j][i];
				}
			}
			cout<<"Transposion of matrix A is as follow"<<endl;
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
				{
					cout<<c[i][j]<<endl;
				}
			}
			break;
		case 4:
			cout<<"Enter the rows and coloumn for matrix B"<<endl;
			cin>>r2>>c2;
			cout<<"Enter the element of matrix B"<<endl;
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					cin>>b[i][j];
				}
			}
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					c[i][j]=a[i][j]+b[i][j];
				}
			}
			cout<<"The addition is as follow"<<endl;
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					cout<<c[i][j]<<endl;
				}
			}
			break;
		case 5:
			cout<<"Enter the rows and coloumn for matrix B"<<endl;
			cin>>r2>>c2;
			cout<<"Enter the element of matrix B"<<endl;
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					cin>>b[i][j];
				}
			}
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					c[i][j]=a[i][j]-b[i][j];
				}
			}
			cout<<"The subtraction is as follow"<<endl;
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					cout<<c[i][j]<<endl;
				}
			}
			break;
		case 6:
			cout<<"Enter the rows and coloumn for matrix B"<<endl;
			cin>>r2>>c2;
			cout<<"Enter the element of matrix B"<<endl;
			for(i=0;i<r2;i++)
			{
				for(j=0;j<c2;j++)
				{
					cin>>b[i][j];
				}
			}
			if(r1==c2)
			{
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
				{
					c[i][j]=0;
				}
			}
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c2;j++)
				{
					for(int k=0;k<r2;k++)
					{
						c[i][j]=c[i][j]+a[i][k]*b[k][j];
					}
				}
			}
			cout<<"The multiplicaction is as follow"<<endl;
			for(i=0;i<r1;i++)
			{
				for(j=0;j<c1;j++)
				{
					cout<<c[i][j]<<endl;
				}
			}
			}
			else
			{
				cout<<"multiplication not possible"<<endl;
			}
			break;
		default:
			cout<<"Invalid choice"<<endl;
	}
	cout<<"Enter y to continue"<<endl;
	cin>>g;
	}while(g=='Y' || g=='y');		
	return 0;
}
	
