#include<iostream>
#include<string.h>
#define max 50
using namespace std;
struct node
{
	char data[max];
	int top;
}st;
class stack
{
	public:
		void push(char item);
		char pop();
		int check(char exp[]);
		int match(char s,char b);
};
int stack::check(char exp[])
{
	int i;
	char temp;
	int n=strlen(exp);
	for(i=0;i<n;i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			push(exp[i]);
		}
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
		{
			if(st.top==-1)
			{
				return 0;
			}
			else
			{
			temp=pop();
			if(!match(temp,exp[i]))
			{
				return 0;
			}
			}
		}
	}
		if(st.top==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}
int stack::match(char a,char b)
{
	if(a=='{' && b=='}')
	{
		return 1;
	}
	if(a=='(' && b==')')
	{
		return 1;
	}	
	if(a=='[' && b==']')
	{
		return 1;
	}
	return 0;
}
void stack::push(char item)
{
	if(st.top==(max-1))
	{
		cout<<"stack is overflow"<<endl;
		return;
	}
	else
	{
		st.top++;
		st.data[st.top]=item;
	}
}
char stack::pop()
{
	if(st.top==-1)
	{
		cout<<"underflow"<<endl;
		exit(1);
	}
	else
	{
		return (st.data[st.top--]);
	}
}		
int main()
{
	int status;
	char exp[max];
	stack obj;
	st.top=-1;
	cout<<"Enter the expresion"<<endl;
	cin>>exp;
	status=obj.check(exp);
	if(status==1)
	{
		cout<<"Expression is well parenthesis"<<endl;
	}
	else
	{
		cout<<"It is not well parenthesis"<<endl;
	}
	return 0;
}


