#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream file("p.txt");
    string s,word,line;
    char ch;
    int count=0;
    int c=0,cnt=0;
    if(!file.is_open())
    {
        cout<<"file can't open";
        return 1;
    }
    while(getline(file,line))
    {
        cout<<line<<endl;
        cnt++;
    }
    file.clear();
    file.seekg(0,ios::beg);
    while(file.get(ch))
    {
        if(!isspace(ch))
        {
            count++;
        }
    }
    file.clear();
    file.seekg(0,ios::beg);
    while(file>>word)
    {
        c++;
    }
    cout<<"\nTotal number of charecters : "<<count;
    cout<<"\nTotal Number of words : "<<c;
    cout<<"\nTotal number of lines : "<<cnt;
}
