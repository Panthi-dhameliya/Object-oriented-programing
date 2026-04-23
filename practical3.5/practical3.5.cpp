#include<iostream>
using namespace std;
int sum(long long n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return (n%10)+sum(n/10);
    }
}
int superdigit(long long n)
{
    if(n<10)
    {
        return n;
    }
    else
    {
        return superdigit(sum(n));
    }
}

int main()
{
    int k;
    long long n;
    cout<<"\nenter Numner : ";
    cin>>n;
    cout<<"\nEnter the Value of K :";
    cin>>k;

    int n_sum=sum(n);
    int result=superdigit(n_sum*k);
    cout << "\nSuper Digit: " << result;
}
