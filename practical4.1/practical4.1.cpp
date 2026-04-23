#include<iostream>
using namespace std;
class DyanamicArray
{
private:
    int *arr;
    int size;
public:
    DyanamicArray()
    {
        arr=nullptr;
        size=0;
    }
    void insert(int value)
    {
        int *newarr=new int[size+1];
        for(int i=0;i<size;i++)
        {
            newarr[i]=arr[i];
        }
        newarr[size]=value;
        delete[]arr;
        arr=newarr;
        size++;
    }
    void delete1(int pos)
    {
        if(size==0)
        {
            cout<<"\nArray is empty";
            return;
        }
        if(pos<0 || pos>=size)
        {
            cout<<"\nInvaild position is Entered";
            return;
        }
        int j=0;
        int* newarr=new int[size-1];
        for(int i=0;i<size;i++)
        {
            if(i!=0)
            {
                newarr[j++]=arr[i];
            }
        }
        delete[] arr;
        arr=newarr;
        size--;

    }
    void display()
    {
        if(size==0)
        {
            cout<<"\nArray is empty";
            return;
        }
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    DyanamicArray d;
    int ch,value,pos;
    do
    {
        cout<<"\n1)->Insert\n2)->Delete\n3)->Display\n4)->Exit";
        cout<<"\nEnter Your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter value: ";
            cin>>value;
            d.insert(value);
            break;
        case 2:
            cout<<"\nEnter position (0-based index): ";
            cin>>pos;
            d.delete1(pos);
            break;
        case 3:
            d.display();
            break;
        case 4:
            cout<<"\nExiting.....";
        }

    }while(ch!=4);
}
