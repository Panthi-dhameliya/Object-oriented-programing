#include<iostream>
using namespace std;
int Iterative(int a[],int n)
{
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
        }
        return sum;
}
int Recursive(int a[],int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return a[n-1]+Recursive(a,n-1);

    }
}
int main()
{
    int n;
    int a[n];
    cout<<"\nEnter size of array : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter elements "<<i+1<<":";
        cin>>a[i];
    }
    cout<<"\nSum using Iterative Method = "<<Iterative(a,n);
    cout<<"\nSum using Recursive Method = "<<Recursive(a,n);
}



