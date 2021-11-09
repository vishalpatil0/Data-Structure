#include <iostream>
#include <stack>
using namespace std;
bool isOperator(char temp)
{
    if (temp == '*' || temp == '/' || temp == '+' || temp == '-' || temp == '(' || temp==')')
    {
        return true;
    }
    else return false;
}
int precendance(char temp)
{
    if(temp == '/' || temp=='*') return 2;
    else if(temp == '+' || temp=='-') return 1;
    else return 0;
}
int main()
{
    string infix, postfix;
    cout << "Enter your infix expression only with [-,+,*,/] this operator = ";
    cin >> infix;
    postfix.resize(infix.size());
    stack<char> stk;
    for (int i = 0; i<infix.size(); i++)
    {
        if (!isOperator(infix[i]))
        {
            postfix.push_back(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(stk.top()!='(')
            {
                postfix.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            if(!stk.empty() && stk.top()=='(')
            {
                stk.push(infix[i]);
            }
            else if(infix[i]=='(')
            {
                stk.push(infix[i]);
            }
            else if(stk.empty() || precendance(infix[i])>precendance(stk.top()))
            {
                stk.push(infix[i]);
            }
            else
            {
                postfix.push_back(stk.top());
                stk.pop();
                stk.push(infix[i]);
            }
        }
    }
    while(!stk.empty())
    {
        postfix.push_back(stk.top());
        stk.pop();
    }
    cout<<postfix<<endl;
    return 0;
}