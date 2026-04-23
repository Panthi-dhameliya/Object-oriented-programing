#include<iostream>
using namespace std;
class shape
{
private:
    float lenght,width;
public:
    void getdata();
    void cal_area();
    void cal_perimeter();
    void display();
    void square();
    float getarea();
};
void shape :: getdata()
{
    cout<<"\nEnter lenght of the  rectangle : ";
    cin>>lenght;
    cout<<"\nEnter width of the  rectangle : ";
    cin>>width;
}
void shape :: cal_area()
{
    cout<<"\nArea of rectangle : "<<lenght*width;
}
void shape :: cal_perimeter()
{

    cout<<"\nPerimeter of rectangle : "<<2*(lenght+width);
    cout<<"\n====================================";
}
float shape :: getarea()
{
    return lenght*width;
}
void shape ::  square()
{
    if(lenght==width)
    {
        cout << "\nThis rectangle is a SQUARE.";
    }
    else
    {
        cout << "\nThis rectangle is  NOT a SQUARE.";
    }
}
void shape :: display()
{
    cout<<"\nLenght : "<<lenght;
    cout<<"\nwidth : "<<width;
    cout<<"\nArea : "<<lenght*width;
    cout<<"\nPerimeter : "<<2*(lenght+width);
     cout<<"\n====================================";

}

int main()
{
    char choice;
    int i=0,ch,f,s;
    shape r[20];
    do
    {
        cout<<"\n1.Add data\n2.Display Area and Perimeter\n3.Display All data\n4.Updating data\n5.cheak square\n6.compare two rectangle\n7.Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {

        case 1:
            do
            {
                r[i].getdata();
                cout <<"\n\nDo you want to add another rectangle? (y/n): ";
                cin >> choice;
                i++;
            }
            while(choice == 'y' || choice == 'Y');
            break;
        case 2:
            for(int j=0; j<i; j++)
            {
                cout<<"\nRectangle "<<j+1;
                r[j].cal_area();
                r[j].cal_perimeter();

            }
            break;
        case 3:
            for(int j=0; j<i; j++)
            {
                cout<<"\nRectangle "<<j+1;
                r[j].display();
                r[j].square();

            }
            break;
        case 4:
            int pos;
            cout<<"\nFor which rectangle do you want to change the dimensions : ";
            cin>>pos;
            if(pos>=1 && pos <=i)
            {
                cout << "\nUpdating Rectangle " << pos << endl;
                r[pos-1].getdata();
            }
            else
            {
                cout << "\nInvalid rectangle number!";
            }
            break;
        case 5:
            for(int j=0; j<i; j++)
            {
                cout<<"\nRectangle "<<j+1;
                r[j].square();
            }
            break;
        case 6:
            cout<<"\nEnter number of two ractangle which you want to compare ";
            cout<<"\nFirst rectangle : ";
            cin>>f;
            cout<<"\nsecond number : ";
            cin>>s;
            float area1=r[f-1].getarea();
            float area2=r[s-1].getarea();
            cout<<"\nArea of reactangle "<<f<<" = "<<area1;
            cout<<"\nArea of reactangle "<<s<<" = "<<area2;
            if(area1>area2)
            {
                cout << "\nRectangle " << f << " has larger area.";
            }
            else if(area1<area2)
            {
                cout << "\nRectangle " << s << " has larger area.";
            }
            else
            {
                cout << "\nInvalid rectangle numbers!";
            }
            break;



        }
    }
    while(ch!=7);
}
