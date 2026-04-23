#include<iostream>
#include<string>
using namespace std;
class account_details
{
private:
    int  wallet_ID;
    string user_name;
    float Current_balance;
    string history[5];
    int cnt=0;
public:
    void loading_money(int);
    void getdata(int);
    void display();
    void transfer(account_details &receiver);
    void add_history(string);
    void show_history();
    void freeze();
    void unfreeze();
    bool isfroze = false;
};
void account_details :: getdata(int i)
{
    cout<<"\nEnter User name :";
    cin.ignore();
    getline(cin,user_name);
    cout<<"\nEnter Wallet ID "<<i<<":";
    cin>>wallet_ID;
    cout<<"\nEnter Current balance :";
    cin>>Current_balance;
}
void account_details :: add_history(string msg)
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
void account_details :: loading_money(int i)
{
    if(isfroze)
    {
        cout<<"\nwallet is frozen.cannot load monet !!";
        return;
    }
    int money;
    cout<<"\nEnter amount of money to loaded in the Wallet"<<i<<":";
    cin>>money;
    Current_balance+=money;
    add_history("\nLoaded Rs. "+ to_string(money));
}
void account_details :: display()
{
    cout<<"==========Details of the account==========";
    cout<<"\nName of the User is"<<user_name;
    cout<<"\nWallet Id of the User is:"<<wallet_ID;
    cout<<"\nCurrent balanceof the User is:"<<Current_balance;

}
void account_details :: transfer(account_details &receiver)
{
     if(isfroze)
    {
        cout<<"\nwallet is frozen.cannot load money !!";
        return;
    }
    int amount;
    cout<<"\nEnter amount to transfer :";
    cin>>amount;
    if(Current_balance>=amount)
    {
        Current_balance-=amount;
        receiver.Current_balance+=amount;
        cout<<"\nTransfer Succesful";
        add_history("\nTransferred Rs."+to_string(amount));
        receiver.add_history("\nReceived Rs."+to_string(amount));

    }
    else
    {
        cout<<"\nInsufficient Balance";
    }
}
void account_details :: show_history()
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
void account_details :: freeze()
{
    isfroze=true;
    cout << "\nWallet frozen successfully.";
    add_history("Wallet frozen");
}
void account_details::unfreeze()
{
    isfroze= false;
    cout << "\nWallet unfrozen successfully.";
    add_history("Wallet unfrozen");
}

int main()
{
    account_details w1,w2;
    int answer,ch,senderchoice;
    cout<<"\nEnter details of wallet 1 ";
    w1.getdata(1);
    cout<<"\nEnter details of wallet 2";
    w2.getdata(2);
    do
    {
        cout<<"\n1.Load Money";
        cout<<"\n2.Transfer Money";
        cout<<"\n3.Display Details";
        cout<<"\n4.Freeze Wallet";
        cout<<"\n5.Unfreeze Wallet";
        cout<<"\n6.Show history";
        cout<<"\n7.Exit";
        cout<<"\nEnter Your Choice";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Loading money into the wallet 1 or 2 :";
            cin>>answer;
            if(answer==1)
            {
                w1.loading_money(1);
            }
            else if(answer==2)
            {
                w2.loading_money(2);
            }
            else
            {
                cout<<"\nInvalid choice";
            }
            break;
        case 2:
            cout<<"\nMake Choice";
            cout<<"\n1.Transfer money from Wallet 1 to  Wallet 2";
            cout<<"\n2.Transfer money from Wallet 2 to  Wallet 1\n";
            cin>>senderchoice;
            if(senderchoice==1)
            {
                w1.transfer(w2);
            }
            else
            {
                w2.transfer(w1);
            }
            break;
        case 3:

            cout<<"\n========Wallet 1 Detail=======\n";
            w1.display();
            cout<<"\n========Wallet 2 Detail=======\n";
            w2.display();
            break;
        case 4:
            cout<<"\nFreeze which wallet (1 or 2) : ";
            cin>>answer;
            if(answer==1)
            {
                w1.freeze();
            }
            else
            {
                w2.freeze();
            }
            break;
        case 5:
            cout<<"\nUnFreeze which wallet (1 or 2) : ";
            cin>>answer;
            if(answer==1)
            {
                w1.unfreeze();
            }
            else
            {
                w2.unfreeze();
            }
            break;
        case 6:
            cout<<"\nWallet 1 Traansaction History : ";
            w1.show_history();
            cout<<"\nWallet 2 Traansaction History : ";
            w2.show_history();
            break;
        case 7:
            cout<<"\nExit";
        }
    }
    while(ch!=7);
}
