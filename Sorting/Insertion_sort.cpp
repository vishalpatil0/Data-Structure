/*
Insertion sort works on the insertion priniciple.

Time Complexity -> O(n^2)

Insertion sort have two part of the array one is Sorted and other is unsorted.
In the 1st pass sorted part have only one element that is index 0 element.
Pass by pass it sort the array by taking element from unsorted part and putting it in sorted part.

It is adaptive {means in case of sorted array its time complexity is O(n).}
It is stable means it keeps the order.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class InsertionSort
{
    T *ptr;
    int length;
    public:
        InsertionSort(int size)
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
            int pass=0,comparision=0,key,j;
            for (int i = 1; i <=length-1; i++)
            {
                key=ptr[i];
                j=i-1;
                cout<<"Working on Pass "<<i<<endl;
                while(j>-1 && ptr[j]>key)
                {
                    ptr[j+1]=ptr[j];
                    j--;
                    comparision++;
                }
                ptr[j+1]=key;
                pass++;
            }
            cout<<"\nTotal Passes = "<<pass<<endl<<"Total Comaparision = "<<comparision<<endl<<endl;
        }
        void descendingSort()
        {
            int pass=0,comparision=0,key,j;
            for (int i = 1; i <=length-1; i++)
            {
                key=ptr[i];
                j=i-1;
                cout<<"Working on Pass "<<i<<endl;
                while(j>-1 && ptr[j]<key)
                {
                    ptr[j+1]=ptr[j];
                    j--;
                    comparision++;
                }
                ptr[j+1]=key;
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
    InsertionSort<int>bs(n);
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