/*
1-Merge sort divid the array in many sub-arrays in equal parts using recusrion until there is only one element in all subarrays is left.

2-And then it start merging the subarray but while merging it place the element at the its position in the array which is formed by merging two sorted array (which are sub arrays).

3-It is stable and works recursively.

4-Time complexity is O(n log n) in all cases.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
template<class T>
class MergeSort
{
    T *arr;
    int length;
    public:
        MergeSort(int size)
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
            for(int j=0;j<length-1;j++)
            {
                if(arr[j]<arr[j+1])
                {
                    return false;
                }
            }
            return true;
        }
        void random_insertion()
        {
            srand(time(0));
            for (int i = 0; i < length; i++)
            {
                arr[i]=rand()%88+10;
            }
        }
        void A_merge(int low,int mid,int high)
        {
            int i=low,j=mid+1,k=0,tarr[high-low+1];
            while(i<=mid && j<=high)
            {
                if(arr[i]<arr[j])
                {
                    tarr[k++]=arr[i++];
                }
                else
                {
                    tarr[k++]=arr[j++];
                }
            }
            while(i<=mid)
            {
                tarr[k++]=arr[i++];
            }
            while(j<=high)
            {
                tarr[k++]=arr[j++];
            }
            for (int i = low,j=0; i <=high; i++,j++)
            {
                arr[i]=tarr[j];
            }    
        }
        void sortA(int low,int high)
        {
            if(low<high)
            {
                int mid=(low+high)/2;
                sortA(low,mid);
                sortA(mid+1,high);
                A_merge(low,mid,high);
            }
        }
        void ascendingSort()
        {
            sortA(0,length-1);
        }
        void D_merge(int low,int mid,int high)
        {
            int i=low,j=mid+1,k=0,tarr[high-low+1];
            while(i<=mid && j<=high)
            {
                if(arr[i]>arr[j])
                {
                    tarr[k++]=arr[i++];
                }
                else
                {
                    tarr[k++]=arr[j++];
                }
            }
            while(i<=mid)
            {
                tarr[k++]=arr[i++];
            }
            while(j<=high)
            {
                tarr[k++]=arr[j++];
            }
            for (int i = low,j=0; i <=high; i++,j++)
            {
                arr[i]=tarr[j];
            }    
        }
        void sortD(int low,int high)
        {
            if(low<high)
            {
                int mid=(low+high)/2;
                sortD(low,mid);
                sortD(mid+1,high);
                D_merge(low,mid,high);
            }
        }
        void descendingSort()
        {
            sortD(0,length-1);
        }
};

int main()
{
    cout<<"Enter the size of the array = ";
    int n;
    cin>>n;
    MergeSort<int>bs(n);
    cout<<"1-Manual insertion\n2-Random insertion\n\nEnter your choice = ";
    int ch;
    cin>>ch;
    if(ch==1)  bs.insertElements();
    else       bs.random_insertion(); 
    cout<<"\nSorted or not -> "<<bs.isSortedforAsscending()<<endl<<endl;
    cout<<"Before sorting array is as follow :"<<endl<<endl;
    bs.print();
    cout<<endl<<endl;
    bs.ascendingSort();
    cout<<"After sorting array is as follow :"<<endl<<endl;
    bs.print();
    cout<<endl<<endl;
    return 0;
}