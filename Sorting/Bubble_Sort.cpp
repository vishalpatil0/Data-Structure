/*
Bubble sort put the largest element in the back first and second largest in the second last position and it goes like that.
Time Complexity is O(n^2).
bcoz number of comparision are  1+2+3+3....+n-1  which n(n+1)/2.

It is stable means it keep the order of the same element.
It is not adaptive but it can be made adpative with n-comparision.

For descending order just put the smallest element at the end;
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class BubbleSort
{
    T *ptr;
    int length;
    public:
        BubbleSort(int size)
        {
            ptr=(T *)calloc(size,sizeof(T));
            this->length=size;
        }
        void insertElements()
        {
            cout<<"\nEnter the elements in the array :"<<endl;
            for (int i = 0; i < length; i++)
            {
                cin>>ptr[i];
            }
        }
        void print()
        {
            for(int i=0;i<length-1;i++) 
            {
                cout<<ptr[i]<<"->";
            }
            cout<<ptr[length-1];
        }
        bool isSortedforAsscending()
        {
            for(int j=0;j<length-1;j++)
            {
                if(ptr[j]>ptr[j+1])
                {
                    return false;
                }
            }
            return true;
        }
        bool isSortedforDescending()
        {
            for (int i = 0; i < length-1; i++)
            {
                for(int j=0;j<length-1-i;j++)
                {
                    if(ptr[j]<ptr[j+1])
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        void asscendingSort()
        {
            int pass=0,comparision=0;
            T temp;
            bool flag=true;
            for (int i = 0; i < length-1; i++)
            {
                cout<<"Working on Pass "<<i+1<<endl;
                for(int j=0;j<length-1-i;j++)
                {
                    if(ptr[j]>ptr[j+1])
                    {
                        temp=ptr[j];
                        ptr[j]=ptr[j+1];
                        ptr[j+1]=temp;
                        flag=false;
                    }
                    comparision++;
                }
                if(flag) 
                {
                    cout<<"\nAlready Sorted"<<endl<<endl;
                    return;
                }
                pass++;
            }
            cout<<"\nTotal Passes = "<<pass<<endl<<"Total Comaparision = "<<comparision<<endl<<endl;
        }
        void descendingSort()
        {
            int pass=0,comparision=0;
            T temp;
            bool flag=true;
            for (int i = 0; i < length-1; i++)
            {
                cout<<"Working on pass "<<i+1<<endl;
                for(int j=0;j<length-1-i;j++)
                {
                    if(ptr[j]<ptr[j+1])
                    {
                        temp=ptr[j];
                        ptr[j]=ptr[j+1];
                        ptr[j+1]=temp;
                        flag=false;
                    }
                    comparision++;
                }
                if(flag)
                {
                    cout<<"\nAlready sorted."<<endl<<endl;
                    return;
                }
                pass++;
            }
            cout<<"\nTotal Passes = "<<pass<<endl<<"Total Comaparision = "<<comparision<<endl<<endl;
        }
};
int main()
{
    cout<<"Enter the size of the array = ";
    int n;
    cin>>n;
    BubbleSort<int>bs(n);
    bs.insertElements();
    cout<<"Sorted or not -> "<<bs.isSortedforAsscending()<<endl<<endl;
    cout<<"Before sorting are is as follow :"<<endl<<endl;
    bs.print();
    cout<<endl<<endl;
    bs.asscendingSort();
    cout<<"After sorting are is as follow :"<<endl<<endl;
    bs.print();
    cout<<endl<<endl;
    return 0;
}