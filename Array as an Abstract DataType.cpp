#include<iostream>
#include<algorithm>
using namespace std;
class MyArray{
        int total_size;
        int used_size;
        int *ptr;
    public:
        MyArray(){}
        MyArray(int tsize, int usize)
        {
            total_size=tsize;
            used_size=usize;
            ptr=new int[total_size];
        }
        ~MyArray()
        {
            delete []ptr;
        }
        void show();
        void set();
        void sorting();
        void insert(int,int);
        void deletion(int);
        bool binarySearch(int);
};
void MyArray::sorting()
{
    sort(ptr,ptr+used_size);
}
void MyArray::show()
{
    cout<<"\n\nElements in array are as follow "<<endl;
    for (int i = 0; i < used_size; i++)
    {
        cout<<ptr[i]<<endl;
    }
}
void MyArray::set()
{
    cout<<"Enter elements in array "<<endl;
    for (int i = 0; i < used_size; i++)
    {
        cin>>ptr[i];
    }
}
void MyArray::insert(int element, int position)
{
    if(used_size==total_size)
    {
        cout<<"Space is full delete some elements"<<endl;
    }
    else
    {
        used_size++;
        for (int i = used_size-1; i >position-1 ; i--)
        {
            ptr[i]=ptr[i-1];
        }
        ptr[position-1]=element;
    }
}
void MyArray::deletion(int element)
{
    int pos;
    bool flag=false;
    for (int i = 0; i < used_size; i++)
    {
        if(element==ptr[i])
        {
            pos=i;
            flag=true;
            break;
        }
    }
    if(flag)
    {
        for (int i = pos; i < used_size; i++)
        {
            ptr[i]=ptr[i+1];
        }
        used_size--;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
}
bool MyArray::binarySearch(int element)
{
    sort(ptr,ptr+used_size);
    int low=0,high=used_size-1;
    int mid=(low+high)/2;
    while(low<=high)
    {
        if(ptr[mid]==element)
        {
            return true;
        }
        else if(element < ptr[mid])
        {
            high=mid-1;
            mid=(low+high)/2;
        }
        else if(element > ptr[mid])
        {
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    return false;
}
int main()
{
    MyArray mrr(100,5);
    mrr.set();
    mrr.sorting(); //for sorting
    mrr.insert(999,3);
    mrr.deletion(999);
    mrr.show();
    cout<<"Present or not = "<<mrr.binarySearch(57)<<endl;
    return 0;
}