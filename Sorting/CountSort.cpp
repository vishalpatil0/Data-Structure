/*
1-In count sort we first find the maximum element in the aray.
2-Create a new array as the size of maximum element.
3-Put zeros as element in every index in the new array.
4-Increment the zero of only those index who are appeared in the original array.
    means zero of 4th index in new array will be increment to 1 bcoz 4 is in the old array.
4-Now element are inserted in old array by inserting the index number until there value get to zeros. 

5-Disadvantage : took extra space.
6-Time complexity O(n).

*/
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class CountSort
{
    T *arr;
    int length;
    public:
        CountSort(int size)
        {
            arr=(T *)calloc(size,sizeof(T));
            this->length=size;
        }
        void insertElements()
        {
            cout<<"\nEnter the elements in the array :"<<endl;
            for (int i = 0; i < length; i++)
            {
                cin>>arr[i];
            }
        }
        void print()
        {
            for(int i=0;i<length-1;i++) 
            {
                cout<<arr[i]<<"->";
            }
            cout<<arr[length-1];
        }
        bool isSortedforAsscending()
        {
            for(int j=0;j<length-1;j++)
            {
                if(arr[j]>arr[j+1])
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
                    if(arr[j]<arr[j+1])
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        void asscendingSort()
        {
            int max=arr[0];
            for (int i = 1; i < length; i++)
            {
                if(max<arr[i])
                {
                    max=arr[i];
                }
            }
            int tarr[max+1]={0};
            for (int i = 0; i <length; i++)
            {
                tarr[arr[i]]++;
            }
            int j=0;
            for (int i = 0; i <=max; i++)
            {
                while(tarr[i]>0)
                {
                    arr[j++]=i;
                    tarr[i]--;
                }
            }
        }
        void descendingSort()
        {
            int max=arr[0];
            for (int i = 1; i < length; i++)
            {
                if(max<arr[i])
                {
                    max=arr[i];
                }
            }
            int tarr[max+1]={0};
            for (int i = 0; i <length; i++)
            {
                tarr[arr[i]]++;
            }
            int j=length-1;
            for (int i = 0; i <=max; i++)
            {
                while(tarr[i]>0)
                {
                    arr[j--]=i;
                    tarr[i]--;
                }
            }
        }
};
int main()
{
    cout<<"Enter the size of the array = ";
    int n;
    cin>>n;
    CountSort<int>bs(n);
    bs.insertElements();
    cout<<"Sorted or not -> "<<bs.isSortedforAsscending()<<endl<<endl;
    cout<<"Before sorting are is as follow :"<<endl<<endl;
    bs.print();
    cout<<endl<<endl;
    bs.descendingSort();
    cout<<"After sorting are is as follow :"<<endl<<endl;
    bs.print();
    cout<<endl<<endl;
    return 0;
}