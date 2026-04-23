#include<iostream>
using namespace std;
class account
{
private:
    int a_number;
    string name;
    int current_balance;
public:
    void getdata();
    bool cheak(string);
    void deposit();
    static void transfer(account a[],int size);
    void display();
};
void account :: getdata()
{
    cout<<"\nEnter Account Number : ";
    cin>>a_number;
    cout<<"\nEnter Account holder’s name : ";
    cin.ignore();
    getline(cin,name);
    cout<<"\nEnter Current balance : ";
    cin>>current_balance;
}
void account :: deposit()
{
    int amount;
    cout<<"\nEnter amount of money to deposit : ";
    cin>>amount;
    current_balance+=amount;
    cout<<"\nMoney is Deposit suceesfully!!!";
}
void account ::  transfer(account a[],int size)
{
    int am;
    string data1,data2;
    int s=-1,r=-1;

        cout<<"\nEnter Sender Account Id or name : ";
        cin>>data1;
        cout<<"Enter Receiver Account Id or name : ";
        cin>>data2;
        for(int j=0; j<size; j++)
        {
            if(a[j].cheak(data1))
            {
                s=j;
            }
            if(a[j].cheak(data2))
            {
                r=j;
            }
        }
        if(s==-1 || r==-1)
        {
            cout<<"\nAccount not found!";
            return;
        }


    cout<<"\nEnter amount to transfer : ";
    cin>>am;
    if(a[s].current_balance < am)
    {
        cout<<"\nInsufficient balance!";
        return ;

    }

    a[s].current_balance -= am;
    a[r].current_balance += am;

    cout<<"\nMoney transferred successfully!!!";


}
void account :: display()
{
    cout<<"\nAccount No: "<<a_number;
    cout<<"\nName: "<<name;
    cout<<"\nBalance: "<<current_balance<<endl;
}
bool account :: cheak(string data)
{
    string str_id=to_string(a_number);
    if(str_id==data || name==data)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int ch,i=0;
    account a[100];
    do
    {
        cout<<"\n1)Add Account\n2)Loading money\n3)Transfer Money\n4)Display\n5)Exit";
        cout<<"\nEnter your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            a[i].getdata();
            i++;
            break;
        case 2:
        {
            string data;
            bool found=false;
            cout<<"\nEnter Account Id or name : ";
            cin>>data;
            for(int j=0; j<i; j++)
            {
                if(a[j].cheak(data))
                {
                    a[j].deposit();
                }
            }
            break;
        }
        case 3:
        {
            account :: transfer(a, i);
            break;
        }
        case 4:
            for(int j=0; j<i; j++)
                a[j].display();
            break;



        }

    }
    while(ch!=4);
}
