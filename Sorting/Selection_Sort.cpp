/*
Selection sort puts the smallest element at the first side and it goes on like that.
It find the minimum element and put it in order.

Time complexity = O(n^2)

Not Adaptive.
Not Stable. Doesn't keep the order.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class SelectionSort
{
    T *ptr;
    int length;
    public:
        SelectionSort(int size)
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
            for(int j=0;j<length-1;j++)
            {
                if(ptr[j]<ptr[j+1])
                {
                    return false;
                }
            }
            return true;
        }
        void asscendingSort()
        {
            short pass=0,comparision=0,swaps=0;
            bool flag=false;
            for (int i = 0; i < length-1; i++)
            {
                int indexofMin=i;
                for (int j = i+1; j < length; j++)
                {
                    if(ptr[indexofMin]>ptr[j])
                    {
                        indexofMin=j;
                        flag=true;
                    }
                    comparision++;
                }
                if(flag)
                {
                    int temp=ptr[indexofMin];
                    ptr[indexofMin]=ptr[i];
                    ptr[i]=temp;
                    flag=false;
                    swaps++;
                }
                pass++;
            }
            cout<<"\nTotal Passes = "<<pass<<endl<<"Total Comaparision = "<<comparision<<endl<<"Total Swaps = "<<swaps<<endl<<endl;
        }
       void descendingSort()
        {
            short pass=0,comparision=0,swaps=0;
            bool flag=false;
            for (int i = 0; i < length-1; i++)
            {
                int indexofMin=i;
                for (int j = i+1; j < length; j++)
                {
                    if(ptr[indexofMin]<ptr[j])
                    {
                        indexofMin=j;
                        flag=true;
                    }
                    comparision++;
                }
                if(flag)
                {
                    int temp=ptr[indexofMin];
                    ptr[indexofMin]=ptr[i];
                    ptr[i]=temp;
                    flag=false;
                    swaps++;
                }
                pass++;
            }
            cout<<"\nTotal Passes = "<<pass<<endl<<"Total Comaparision = "<<comparision<<endl<<"Total Swaps = "<<swaps<<endl<<endl;
        }
};
int main()
{
    cout<<"Enter the size of the array = ";
    int n;
    cin>>n;
    SelectionSort<int>bs(n);
    bs.insertElements();
    cout<<"\nSorted or not -> "<<bs.isSortedforAsscending()<<endl<<endl;
    cout<<"Before sorting are is as follow :"<<endl<<endl;
    bs.print();
    cout<<endl<<endl;
    bs.descendingSort();
    cout<<"After sorting are is as follow :"<<endl<<endl;
    bs.print();
    cout<<endl<<endl;
    return 0;
}