#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class loan
{
private:
    int id;
    string name;
    int amount;
    float rate;
    int time;
public:
    loan()
    {
        id=1001;
        name="Rahul Sharma";
        amount=50000;
        rate=8.5;
        time=60;

    }
    loan(int i,string n,int a,float r,int t)
    {
        id=i;
        name=n;
        amount=a;
        rate=r;
        time=t;
    }
    void display();
    float cal_emi();
};
float loan :: cal_emi()
{
    if(amount <= 0 || time <= 0)
    {
        cout<<"\nInvalid Loan Amount or Tenure!";
        return 0;
    }
    else
    {
        float monthly_rate=rate/12/100;
        return (amount*monthly_rate*(pow(1+monthly_rate,time)))/
               (pow(1+monthly_rate,time)-1);
    }

}
void loan :: display()
{
    cout<<"\nLoan ID             : "<<id;
    cout<<"\nApplicant Name      : "<<name;
    cout<<"\nLoan Amount         : "<<amount;
    cout<<"\nAnnual Interest Rate: "<<rate<<"%";
    cout<<"\nLoan Tenure         : "<<time<<" month";
    cout<<"\n\nCalculated Monthly EMI : "<<cal_emi();
    cout<<"\nTotal Repayment Amount : "<<cal_emi()*time;
    cout<<"\nTotal Interest Paid    : "<<(cal_emi()*time)-amount;
}
int main()
{
    int id;
    string name;
    int amount;
    float rate;
    int time;
    cout<<"================ LOAN MANAGEMENT SYSTEM ================";
    loan l1;
    cout<<"\n\n----------- Loan Details (Default Constructor) -----------";
    l1.display();
    loan l2(1002,"Priya Patel",750000,9,48);
    cout<<"\n\n----------- Loan Details (Parameterized Constructor) -----------";
    l2.display();

}
