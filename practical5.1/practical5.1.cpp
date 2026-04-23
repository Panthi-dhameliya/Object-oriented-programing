#include<iostream>
#include<string>
using namespace std;
int main()
{
    string paragraph;
    cout<<"\nEnter the paragraph : ";
    getline(cin,paragraph);
    for(int i=0;paragraph[i]!='\0';i++)
    {
        if(paragraph[i]>='A' && paragraph[i]<='Z')
        {
            paragraph[i]+=32;
        }
    }
    string word[100];
    char ch;
    string temp="";
    int count=0;
    for(int i=0;paragraph[i]!='\0';i++)
    {
        ch=paragraph[i];
        if(ch!=' ')
        {
            temp+=ch;

        }
        else
        {
            word[count++]=temp;
            temp="";
        }
    }
    if(temp!="")
    {
        word[count++]=temp;

    }
    bool visit[100]={false};
    for(int i=0;i<count;i++)
    {
        if(visit[i]==true)
        {
            continue;
        }
        int feq=1;
        for(int j=i+1;j<count;j++)
        {
            if(word[i]==word[j])
            {
                feq++;
                visit[j]=true;
            }

        }
        cout<<word[i]<<"="<<feq<<endl;
    }


}

