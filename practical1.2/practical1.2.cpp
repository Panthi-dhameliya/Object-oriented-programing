#include<iostream>
#include<string>
#include<ctime>
using namespace std;
class book
{
private:
    int book_id;
    string title;
    string author;
    int number_of_available_copies;
    int x;
    int issue_day,issue_month,issue_year;
public:
    void add_book();
    void display();
    bool issue_book(string);
    bool return_book(string);
};
void book :: add_book()
{
    cout<<"\nEnter Book ID : ";
    cin>>book_id;
    cout<<"\nEnter Title of the Book : ";
    cin >> ws;
    getline(cin,title);
    cout<<"\nEnter Book Author name : ";
    cin>> ws;
    getline(cin,author);
    cout<<"\nEnter Number of available copies : ";
    cin>>number_of_available_copies;
    x=number_of_available_copies;
}
void book :: display()
{
    cout<<"\nBook ID : "<<book_id;
    cout<<"\nTitle of the Book : "<<title;
    cout<<"\nAuthor of the Book : "<<author;
    cout<<"\nNumber of available copies : "<<number_of_available_copies;
    cout<<"\n=============================================";
}
bool book :: issue_book(string issue)
{

    string id_str=to_string(book_id);
    if(issue == id_str || issue==title)
    {
        if(number_of_available_copies>0)
        {
            time_t t =time(0);
            tm *now=localtime(&t);
            issue_day=now->tm_mday;
            issue_month=now->tm_mon+1;
            issue_year=now->tm_year+1900;
            cout<<"\nBook issued successfulliy.";
            cout<<"\nIsuue Date : "<<issue_day <<" / "<<issue_month<<" / "<< issue_year;
            cout << "\nDue Period : 7 days";
            number_of_available_copies-=1;
            cout<<"\nRemaining copies : "<<number_of_available_copies;
            return true;
        }
        else
        {
            cout<<"\nNo copies are available";
            return true;
        }

    }
    return false;
}
bool book :: return_book(string returnn)
{

    string id_str=to_string(book_id);

    if(returnn == id_str || returnn==title)
    {
        if(number_of_available_copies<x)
        {
            int r_day,r_month,r_year;
            cout <<"\nEnter Return Date (dd mm yyyy) : ";
            cin >> r_day >> r_month >> r_year;
            int issue_total = issue_year*365+issue_month*30+issue_day;
            int return_total = r_year * 365 + r_month * 30 + r_day;
            int days_taken = return_total - issue_total;
            cout<<"\nReturn Date : "<<r_day <<" / "<<r_month<<" / "<< r_year;
            if (days_taken > 7)
            {
                int num_of_fine_dat=days_taken-7;
                int fine=50*num_of_fine_dat;
                         cout << "\nLate Return!";
                cout << "\nFine Applied : Rs. "<<fine;
            }
            else
            {
                cout << "\nReturned within due date.";
                cout << "\nNo Fine.";
            }
            cout<<"\nBook return successfulliy.";
            number_of_available_copies+=1;
            cout<<"\nRemaining copies : "<<number_of_available_copies;
            return true;
        }
        else
        {
            cout<<"This Book never issued!!";
            return true;
        }


    }
    return false;
}
int main()
{
    book b[100];
    int i=0;
    int ch;
    bool found;
    do
    {
        cout<<"\n1.Adding new books to the library";
        cout<<"\n2.Display all the Book details";
        cout<<"\n3.Issuing a book to a student";
        cout<<"\n4.Returning a book to a student";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            b[i].add_book();
            i++;
            break;
        case 2:
            cout<<"\n=========All The Book Details=============";
            for(int j=0; j<i; j++)
            {
                b[j].display();

            }

            break;
        case 3:
        {
            string issue;
            cout<<"\nEnter Book Id or Book name to issue : ";
            cin.ignore();
            getline(cin,issue);
            found = false;
            for(int j=0; j<i; j++)
            {
                if(b[j].issue_book(issue))
                    found = true;
            }
            if (!found)
                cout << "\nBook not found!";
            break;
        }
        case 4:
        {
            string returnn;
            cout<<"\nEnter Book Id or Book name to return : ";
            cin.ignore();
            found = false;
            getline(cin,returnn);
            for(int j=0; j<i; j++)
            {
                if(b[j].return_book(returnn))
                {
                    found = true;
                }
            }
            if (!found)
                cout << "\nBook not found!";
            break;
        }
        case 5:
            cout<<"\nExit";
        }
    }
    while(ch!=5);

}
