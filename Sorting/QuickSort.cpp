/*
-Quick sort works on divide and conquer.
-Quick sort select an element as pivot in the array.
-Pivot can be first element, last element, middle element and any random element.

-In the partition process pivot is placed at the position where right element are the greatest and left are the lowest (in the ascednding order.)

-Basically pivot is placed at its right position in the array so in this way element are placed in the array by selecting pivot and putting them at the right place.

-Time Complexity : 
        Best Case : O(n log n)
            when pivot is getting in the middle of the array at every partition.
        
        Worst Case : O(n^2)
            When pivot is getting at the edge of array at every partition.
            Example :- When array is sorted.
        
-Quick sort is not stable.
-Not adaptive means when array is sorted it take more time.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
class QuickSort
{
    T *arr;
    int length;
    public:
        QuickSort(int size)
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
        void sortA(int low,int high)
        {
            if(low<high)
            {
                int partitionIndex=A_partition(low,high);
                sortA(low,partitionIndex-1);
                sortA(partitionIndex+1,high);
            }
        }
        int A_partition(int low,int high)
        {
            T pivot=arr[low];
            int i=low+1;
            int j=high;
            
            do
            {
                while((arr[i]<=pivot) && (i<high))
                {
                    i++;
                }
                while((arr[j]>pivot) && (j>low))
                {
                    j--;
                }
                if(i<j)
                {
                    T temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            } while (i<j);

            T temp=arr[j];
            arr[j]=arr[low];
            arr[low]=temp;

            return j;
        }
        void asscendingSort()
        {
            sortA(0,length-1);
        }
        int D_partition(int low,int high)
        {
            T pivot=arr[low];
            int i=low+1;
            int j=high;
            
            do
            {
                while((arr[i]>pivot) && (i<high))
                {
                    i++;
                }
                while((arr[j]<=pivot) && (j>low))
                {
                    j--;
                }
                if(i<j)
                {
                    T temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            } while (i<j);

            T temp=arr[j];
            arr[j]=arr[low];
            arr[low]=temp;

            return j;
        }
        void sortD(int low,int high)
        {
            if(low<high)
            {
                int partitionIndex=D_partition(low,high);
                sortD(low,partitionIndex-1);
                sortD(partitionIndex+1,high);
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
    QuickSort<int>bs(n);
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