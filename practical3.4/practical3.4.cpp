#include<iostream>
using namespace std;
template <class T>
T  findmax(T arr[],int n)
{
    T max=arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}
template <class T>
void display(T arr[],int n)
{
    for(int i=0;i<n;i++)
    {
     cout<<arr[i]<<" ";
    }
     cout<<endl;
}
template <class T>
void max_from_right(T arr[],int n)
{
    T leader=arr[n-1];
    cout<<leader<<" ";
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>leader)
        {
            leader=arr[i];
            cout<<arr[i]<<" ";
        }
    }
}
int main()
{
    int a[] = {16,17,4,3,5,2};
    float b[] = {1.5, 3.2, 2.8, 5.1};
    char c[] = {'A','Z','B','Y'};

    int n1=6, n2=4, n3=4;

    cout<<"Integer Array:\n";
    display(a,n1);
    cout<<"max : "<<findmax(a,n1)<<endl;
    cout<<"Leader : ";
    max_from_right(a,n1);
    cout<<endl;
    cout<<endl;
    cout<<"Float Array:\n";
    display(b,n2);
    cout<<"max : "<<findmax(b,n2)<<endl;
    cout<<"Leader : ";
    max_from_right(b,n2);
    cout<<endl;
    cout<<endl;
    cout<<"Character Array:\n";
    display(c,n3);
    cout<<"max : "<<findmax(c,n3)<<endl;
    cout<<"Leader : ";
    max_from_right(c,n3);
    cout<<endl;
}
