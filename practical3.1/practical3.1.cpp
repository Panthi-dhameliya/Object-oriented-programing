#include<iostream>
#include<string>
using namespace std;
class salary
{
private:
    string name;
    int basic_salary;
    int Bonus;
public:
    salary()
    {
        Bonus=5000;
    }
    void getdata(int);
    int total_salary()
    {
        return Bonus+basic_salary;
    }
    void display(int);
    string grade();
    bool cheak(string);
    void Increment_salary();
};
void salary :: getdata(int i)
{
    string choice;
    cout<<"\n----------- Employee "<<i<<" Details -----------";
    cout<<"\nEnter Employee Name  : ";
    cin>>ws;
    getline(cin,name);
    do
    {
        cout<<"\nEnter Basic Salary   : ";
        cin>>basic_salary;
        if(basic_salary<0)
        {
            cout<<"\nEnter valid salary!!!\n";
        }
    }
    while(basic_salary<0);
    cout<<"\nDo you want apply Custom Bonus (yes/no) : ";
    cin>>ws;
    getline(cin,choice);
    if(choice=="yes")
    {
        cout<<"\nEnter Custom Bonus   : ";
        cin>>Bonus;
    }
    else
    {
        cout<<"\nDefault Bonus Applied ("<<Bonus<<")";
    }
}
bool salary :: cheak(string data)
{
    if(name==data)
    {
        return true;
    }
    return false;
}
void salary :: display(int i)
{
    cout<<"\n\n----------- Employee "<<i<<" Salary Details -----------";
    cout<<"\nEmployee Name  : "<<name;
    cout<<"\nBasic Salary   : "<<basic_salary;
    cout<<"\nBonus          : "<<Bonus;
    cout<<"\nTotal Salary   : "<<total_salary();
    cout<<"\nGrade          : "<<grade();
}
string salary :: grade()
{
    if(total_salary()>=100000)
    {
        return "A";
    }
    else if(total_salary()>=50000)
    {
        return "B";
    }
    else if(total_salary()>=20000)
    {
        return "C";
    }
    else
    {
        return "D";
    }

}
void salary :: Increment_salary()
{
    int i;
    cout<<"\nEnter Bonus Increment :";
    cin>>i;
    Bonus+=i;
    cout<<"\nBonus Updated Successfully!";
}
int main()
{
    int n,cou=1,c=1,ch;
    cout<<"================ PAYROLL MANAGEMENT SYSTEM ================";
    cout<<"\nHow many employees? : ";
    cin>>n;
    salary s[n];
    for(int j=0; j<n; j++)
    {
        s[j].getdata(cou++);
    }

    do
    {
        cout<<"\n1).Display employee Ditail\n2).Diplay all employees details\n3).Bonus Appraisal Update\n4).Exit";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            string data;
            bool found=false;
            cout<<"\nEnter Employee name to display detail : ";
            cin>>ws;
            getline(cin,data);
            for(int j=0; j<n; j++)
            {
                if(s[j].cheak(data))
                {
                    s[j].display(j+1);
                    found=true;

                }
            }
            if(!found)
            {
                cout<<"\nEmployee does't Exit!!!";
            }
        }
        break;

    case 2:
        {
            for(int j=0; j<n; j++)
            {
                s[j].display(c++);
            }
        }
        break;
    case 3:
        {
            string data;
            int i_salary;
            bool found;
            found=false;
            cout<<"\n================ BONUS APPRAISAL UPDATE ================\n";
            cout<<"\nEnter Employee name to Updating Bonus : ";
            cin>>ws;
            getline(cin,data);
            for(int j=0; j<n; j++)
            {
                if(s[j].cheak(data))
                {
                    s[j].Increment_salary();
                    found=true;

                }
            }
            if(!found)
            {
                cout<<"\nEmployee does't Exit!!!";
            }
        }
        break;
        case 4:
            cout<<"\nExiting Program...";
            break;

        default:
            cout<<"\nInvalid Choice!";
    }


}
while(ch!=4);


}

