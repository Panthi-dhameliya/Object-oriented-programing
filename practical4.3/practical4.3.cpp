#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"\nEnter the size of the first array : ";
    cin>>n;
    int *arr1= new int[n];
    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter Element "<<i+1<<" : ";
        cin>>arr1[i];
    }
    cout<<"\nEnter the size of the Second array : ";
    cin>>m;
    int *arr2 = new int[m];
    int *arr3 = new int[n+m];

    for(int i=0; i<m; i++)
    {
        cout<<"\nEnter Element : "<<i+1<<" : ";
        cin>>arr2[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                swap(arr1[j],arr1[j+1]);
            }
        }
    }
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<m-i-1;j++)
        {
            if(arr2[j]>arr2[j+1])
            {
                swap(arr2[j],arr2[j+1]);
            }
        }
    }
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
        }
        else
        {
            arr3[k]=arr2[j];
            j++;
        }
        k++;

    }

    while(i<n)
    {
        arr3[k]=arr1[i];
        i++;
        k++;
    }

    while(j<m)
    {
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    for(int i=0; i<n+m; i++)
    {
        cout<<"\n"<<arr3[i];
    }
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;


}
