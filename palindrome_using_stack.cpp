#include<iostream>
#include<string.h>
using namespace std;
#define max 50
class stack
{
	public:
		char str[max],data[max];
		int length,top,count;
		stack()
		{
			length=0;
			count=0;
			top=-1;
		}
		void getpalin();
		void push(char);
		char pop();
		void getstring();
};
int main()
{
	stack s;
	s.getstring();
	s.getpalin();
	return 0;
}
void stack::getstring()
{
	cout<<"Enter the string"<<endl;
	cin.getline(str,max);
	length=strlen(str);
}
void stack::getpalin()
{
	for(int i=0;i<length;i++)
	{
		push(str[i]);
	}
	for(int i=0;i<length;i++)
	{
		if(str[i]==pop())
		{
			count++;
		}
	}
	if(count==length)
	{
		cout<<"It is palindrome"<<endl;
	}
	else
	{
		cout<<"It is not palindrome"<<endl;
	}
}
void stack::push(char v)
{
	if(top>=max-1)
	{
		cout<<"Stack is full"<<endl;
	}
	else
	{
		top++;
		data[top]=v;
	}
}
char stack::pop()
{
	if(top==max-1)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		char ch=data[top];
		top--;
		return ch;
	}
}

