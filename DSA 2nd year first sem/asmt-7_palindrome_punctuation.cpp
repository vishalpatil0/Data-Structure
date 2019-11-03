#include<iostream>
#include<string.h>
#define max 50
using namespace std;

class stack
{
	public:
		char str[max],data[max];
		string exp;
		int length,count,top;
		stack()
		{
			length=0;
			count=0;
			top=-1;
		}
		void push(char a);
		char pop()
		{

			char b;
			if(top==-1)
			{
				cout<<"Stack is empty"<<endl;
			}
			else
			{
				b=data[top];
				top--;
			}
			return b;
		}
		void getstring();
		void getstring1();
		void getpalin()
		{
			for(int i=0;i<length;i++)
			{
				push(str[i]);
			}
			char temp;
			for(int i=0;i<length;i++)
			{
				if(str[i]==pop())
				{
					count++;
				}
			}
			if(count==length)
			{
				cout<<"this is palindrome"<<endl;
			}
			else
			{
				cout<<"This is not palindrome"<<endl;
			}
		}
		void reverse()
		{
			for(int i=0;i<length;i++)
			{
				push(str[i]);
			}
			cout<<endl;
			for(int i=0;i<length;i++)
			{
				cout<<pop();
			}
			cout<<endl;
		}	
		void punc()
		{
			char dst[max];
			int i,j;
			i=0,j=0;
			while(str[i]!='\0')
			{
				if(ispunct((unsigned char)str[i])||str[i]==' ')
				{
					i++;
				}
				else if(isupper((unsigned char)str[i]))
				{
					dst[j]=tolower((unsigned char)str[i]);
					i++;
					j++;
				}
				else
				{
					dst[j]=str[i];
					j++;
					i++;
				}
			}
			dst[j]='\0';
			cout<<dst<<endl;
		}
};
void stack::push(char a)
{
	if(top==max-1)
	{
		cout<<"stack is full"<<endl;
	}
	else
	{
		top++;
		data[top]=a;
	}
}
void stack::getstring()
{
	cout<<"Enter the string for which you want to check palindrome"<<endl;
	cin.ignore();
	cin.getline(str,max);
	cout<<"string get scanned"<<endl;
	length=strlen(str);
}
int main()
{
	int ch;
	char y;
	do{
	stack s;
	cout<<"------------------------------------"<<endl;
	cout<<"1-palindrome\n2-Reverse string\n3-remove punctuation\nEnter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			s.getstring();
			s.getpalin();
			break;
		case 2:
			s.getstring();
			s.reverse();
			break;
		case 3:
			s.getstring();
			s.punc();
			break;
		default:
			cout<<"invalid choice"<<endl;
	}
	cout<<"Enter y to continue"<<endl;
	cin>>y;
	}while(y=='Y' || y=='y');
	return 0;
}		
