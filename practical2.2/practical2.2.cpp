#include<iostream>
using namespace std;
class student
{
private:

    string name;
    int id;
    int marks[3];
    float a;
public:
    student(){}
    student(string na,int roll,int m[])
    {
        name=na;
        id=roll;
        for(int i=0; i<3; i++)
        {
            marks[i]=m[i];
        }
    }
    void getdata();
    void putdata();
    float average();
    string getname();
};
void student :: getdata()
{
    cout<<"\nEnter details of the Student ";
    cout<<"\n\nEnter Name of the Student : ";
    cin >> ws;
    getline(cin, name);
    cout<<"\nEnter ID of the student : ";
    cin>>id;
    for(int i=0; i<3; i++)
    {
        cout<<"\nEnter Marks of subject "<<i+1<<" :";
        cin>>marks[i];
    }
}
float student :: average()
{
    a=(marks[0]+marks[1]+marks[2])/3.0;
    return a;
}
string student :: getname()
{
    return name;
}
void student :: putdata()
{

    cout<<"\nName of the Student : "<<name;
    cout<<"\nID of the student : "<<id;
    for(int i=0; i<3; i++)
    {
        cout<<"\nMarks of subject "<<i+1<<" : "<<marks[i];

    }
    cout<<"\nAverage of the marks : "<< average();
    cout<<"\n=========================================================";

}

int main()
{
    int n,m[3],roll;
    string na;
    cout<<"\nEnter Total number of student : ";
    cin>>n;
    student s[n];
    for(int i=0; i<n; i++)
    {

        cout<<"\n======== Enter details of the Student " <<i+1<<" ========";
        cout<<"\n\nEnter Name of the Student : ";
        cin >> ws;
        getline(cin, na);
        cout<<"\nEnter ID of the student : ";
        cin>>roll;
        for(int j=0; j<3; j++)
        {
            cout<<"\nEnter Marks of subject "<<j+1<<" :";
            cin>>m[j];
        }
        s[i]=student(na,roll,m);
    }
    cout<<"\n==========Display details of the Student=============";
    for (int i = 0; i < n; i++)
    {
        s[i].putdata();
    }
    float max_avg=s[0].average();
    string topper=s[0].getname();
    for (int i = 0; i < n; i++)
    {
        if(max_avg<s[i].average())
        {
            max_avg=s[i].average();
            topper=s[i].getname();
        }
    }
    cout<<"\n\nTopper name : "<<topper;
    cout<<"\nHighest average  : " << max_avg;

}
