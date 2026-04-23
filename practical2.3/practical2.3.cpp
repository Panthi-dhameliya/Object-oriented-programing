#include<iostream>
#include<string>
using namespace std;
class account
{
private:
    string name;
    int account_ID;
    int balance;
    string history[5];
    int cnt=0;
public:
    account()
    {
        balance=0;

    }
    void getdata(int &id,bool first);
    bool cheak(string);
    void deposit();
    void withdraw();
    void display();
    void apply_interst();
    void active();
    void inactive();
    void add_history(string);
    void show_history();
    bool isactive=false;

};
void account :: getdata(int &id,bool first)
{
    cout<<"\nEnter Customer Name : ";
    cin>>ws;
    getline(cin,name);
    if(first)
    {
        cout<<"\nEnter Account ID : ";
        cin>>id;
    }
    else
    {
        id=id+1;
        cout<<"\nAccount ID (Auto Generated) : " << id << endl;
    }
    account_ID = id;
    cout<<"\nEnter Initial Balance (0 if none) : ";
    cin>>balance;
    cout<<"\nAccount Created Successfully!\n";
}
void account :: add_history(string msg)
{
    if(cnt<5)
    {
        history[cnt]=msg;
        cnt++;
    }
    else
    {
         for(int i=0; i<4; i++)
        {
            history[i]=history[i+1];

        }
        history[4]=msg;
    }
}
bool account :: cheak(string d)
{
    string a_id=to_string(account_ID);
    if(d==a_id || d==name)
    {
        return true;
    }
    return false;
}
void account :: deposit()
{
    if(isactive)
    {
        cout<<"\nAccount is Inactive Now!!!";
        return;

    }
    int deposit_amount;
    cout<<"\nEnter amount of Money to Deposit : ";
    cin>>deposit_amount;
    balance+=deposit_amount;
    cout << "\nDeposit Successful!";
    add_history("\nDeposit money : "+to_string(deposit_amount));
}
void account :: withdraw()
{
    if(isactive)
    {
        cout<<"\nAccount is Inactive Now!!!";
        return;

    }
    int withdra_amount;
    cout<<"\nEnter amount of Money to withdraw : ";
    cin>>withdra_amount;
    if(withdra_amount>balance)
    {
        cout << "\nInsufficient Balance!";
    }
    else
    {
        balance-=withdra_amount;
        cout << "\nWithdrawal Successful!";
    }
    add_history("\nWithdraw money : "+to_string(withdra_amount));
}
void account :: display()
{
    cout << "\n-----------------------------";
    cout << "\nCustomer Name : " << name;
    cout << "\nAccount ID    : " << account_ID;
    cout << "\nBalance       : " << balance;
    cout << "\n-----------------------------";
}
void account :: apply_interst()
{
    float rate;
    cout<<"\nEnter Interest Rate(%) : ";
    cin>>rate;
    float interst=(balance*rate)/100;
    balance+=interst;
    cout << "\nInterest Added Successfully!";
    cout << "\nInterest Amount : " << interst;
}
void account :: active()
{
    isactive=true;
    cout<<"\nAccount active Successfully!";
    add_history("\nAccount is active");
}
void account :: inactive()
{
    isactive=false;
    cout<<"\nAccount Inactive Successfully!";
    add_history("\nAccount is Inactive");

}
void account :: show_history()
{
    if(cnt==0)
    {
        cout<<"\nNO transactions Yet.";
    }
    for(int i=0; i<cnt; i++)
    {
        cout<< history[i]<<endl;
    }
}
int main()
{
    int n,ch,i=1;
    int id;
    cout<<"\n================ DIGITAL SAVINGS ACCOUNT SYSTEM ================";
    account a[15];
    cout<<"\n\n\n================ TRANSACTION MENU ================";
    do
    {
        cout<<"\n1.Creat Account";
        cout<<"\n2.Deposit";
        cout<<"\n3.Withdraw";
        cout<<"\n4.Display Account Summary";
        cout<<"\n5.Add interest to balance";
        cout<<"\n6.Active account";
        cout<<"\n7.Inactive account";
        cout<<"\n8.show History";
        cout<<"\n9.Exit";
        cout<<"\n\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:


            cout<<"\n\n------------ Create Account " <<i<<" ------------\n";
            if(i==1)
            {
                a[i].getdata(id,true);
            }
            else
            {
                a[i].getdata(id,false);
            }
            i++;
            break;
        case 2:
        {
            string d;
            cout<<"\nEnter Account ID or Customer Name : ";
            cin>>d;
            bool found=false;
            for(int j=1; j<i; j++)
            {
                if(a[j].cheak(d))
                {
                    a[j].deposit();
                    found=true;
                }

            }
            if(!found)
            {
                cout<<"\nAccount does't Exit!!!";
            }
            break;
        }


        case 3:
        {
            string d;
            cout<<"\nEnter Account ID or Customer Name : ";
            cin>>d;
            bool found=false;
            for(int j=1; j<i; j++)
            {
                if(a[j].cheak(d))
                {
                    a[j].withdraw();
                    found=true;
                }

            }
            if(!found)
            {
                cout<<"\nAccount does't Exit!!!";
            }
            break;
        }
        case 4:
        {
            string d;
            cout<<"\nEnter Account ID or Customer Name : ";
            cin>>d;
            bool found=false;
            for(int j=1; j<i; j++)
            {
                if(a[j].cheak(d))
                {
                    a[j].display();
                    found=true;
                }

            }
            if(!found)
            {
                cout<<"\nAccount does't Exit!!!";
            }
            break;
        }
        case 5:
        {
            string d;
            cout<<"\nEnter Account ID or Customer Name : ";
            cin>>d;
            bool found=false;
            for(int j=1; j<i; j++)
            {
                if(a[j].cheak(d))
                {
                    a[j].apply_interst();
                    found=true;
                }

            }
            if(!found)
            {
                cout<<"\nAccount does't Exit!!!";
            }
            break;
        }

        case 6:{
            string d;
            cout<<"\nEnter Account ID or Customer Name to active : ";
            cin>>d;
            bool found=false;
            for(int j=1; j<i; j++)
            {
                if(a[j].cheak(d))
                {
                    a[j].active();
                    found=true;
                }

            }
            if(!found)
            {
                cout<<"\nAccount does't Exit!!!";
            }
            break;
        }
        case 7:
            {
            string d;
            cout<<"\nEnter Account ID or Customer Name to Inactive: ";
            cin>>d;
            bool found=false;
            for(int j=1; j<i; j++)
            {
                if(a[j].cheak(d))
                {
                    a[j].inactive();
                    found=true;
                }

            }
            if(!found)
            {
                cout<<"\nAccount does't Exit!!!";
            }
            break;
        }
        case 8:
            {
            string d;
            cout<<"\nEnter Account ID or Customer Name to Inactive: ";
            cin>>d;
            bool found=false;
            for(int j=1; j<i; j++)
            {
                if(a[j].cheak(d))
                {
                    a[j].show_history();
                    found=true;
                }

            }
            if(!found)
            {
                cout<<"\nAccount does't Exit!!!";
            }
            break;
        }
        case 9:
            cout << "\nThank You for Using the System!";
            break;
        default:
            cout << "\nInvalid Choice!";


        }

    }
    while(ch!=9);

}
