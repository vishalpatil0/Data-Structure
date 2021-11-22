#include<iostream>
using namespace std;

bool check(char ch)
{
/*0 = 48 || 1 = 49 || 2 = 50 || 3 = 51 || 4 = 52 || 5 = 53 || 6 = 54 || 7 = 55 || 8 = 56 || 9 = 57*/
       if(int(ch)>47 && int(ch)<58)
       {
              return true;
       }
       return false;
}
int main()
{
    string str;
    getline(cin,str);
    int count=0;
    int i=0;
       if(str[1]!=' ')
       {
              if(check(str[1]))
              {
                     cout<<"str[1] checked"<<endl<<endl;
                     i=2;
                     count++;
              }
       }
    
    for(;i<str.size();i++)
    {
       
        if(str[i]==' ')
        {
         if(check(str[i+2]))
            {
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}