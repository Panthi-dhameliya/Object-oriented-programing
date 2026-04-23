#include<iostream>
#include<string>
using namespace std;
class item
{
private:
    int id;
    string name;
    float price;
    int quantity;
public:
    item() {}
    item(int i,string n,float p,int q)
    {
        id=i;
        name=n;
        price=p;
        quantity=q;

    }
    void getdata();
    bool cheak(string);
    void add();
    void sale();
    void display();
    int get_quantity();
    void print_sort();
    void discount();
};
bool item :: cheak(string data)
{
    string i_id=to_string(id);
    if(data==i_id || data==name)
    {
        return true;
    }
    return false;
}
void item :: add()
{
    int new_stock;
    cout<<"\nEnter Quantity to Add: ";
    cin>>new_stock;
    quantity+=new_stock;
    cout<<"\nStock Updated Successfully!";
}
void item :: sale()
{
    int sale_stock;
    if(sale_stock>quantity)
    {
        cout << "\nInsufficient Stock!";
        cout << "\nAvailable Quantity: " << quantity << endl;
    }
    else
    {
        cout<<"\nEnter Quantity to sell: ";
        cin>>sale_stock;
        quantity-=sale_stock;
        cout<<"\nSale Successfully!";
    }

}
int item :: get_quantity()
{
    return quantity;
}
void item :: discount()
{
    int per;
    cout<<"\nEnter Discount Percentage: ";
    cin>>per;
    price-=(price*per/100);
    cout<<"\nNew Price after Discount: " << price;

}
void item :: print_sort()
{
    cout << "\nItem ID: " << id;
    cout << "\nStock Quantity: " << quantity << endl;
}

void item :: display()
{
    cout<<"\n---------------- ITEM DETAILS ----------------";
    cout<<"\nItem ID       : "<<id;
    cout<<"\nItem Name     : "<<name;
    cout<<"\nPrice         : "<<price;
    cout<<"\nStock Quantity: "<<quantity;
    cout<<"\n----------------------------------------------";
}
int main()
{
    int ch,countt=0;
    item i[10];
    cout<<"\n================ RETAIL STORE INVENTORY SYSTEM ================";
    do
    {
        cout<<"\n------------------ INVENTORY MENU ------------------";
        cout<<"\n1. Add New Item\n2. Increase Stock\n3. Sell Item\n4. Display Item Details\n5. Display All Items\n6.low inventory\n7.Discount\n8.Sort Items Based on Quantity\n9. Exit";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            int id,qty;
            string name;
            float price;
            cout<<"\nEnter Item ID: ";
            cin>>id;
            cout<<"\nEnter Item Name: ";
            cin>>ws;
            getline(cin,name);
            cout<<"\nEnter Price: ";
            cin>>price;
            cout<<"\nEnter Initial Quantity: ";
            cin>>qty;
            i[countt]= item(id,name,price,qty);
            countt++;
            break;
        }
        case 2:
        {
            string data;
            cout<<"\nEnter Item ID or Name: ";
            cin>>ws;
            getline(cin,data);
            bool found = false;
            for(int j=0; j<countt; j++)
            {
                if(i[j].cheak(data))
                {
                    i[j].add();
                    found = true;
                }

            }
            if(!found)
            {
                cout<<"\nItem does't exit!!!";
            }
            break;
        }
        case 3:
        {
            string data;
            cout<<"\nEnter Item ID or Name: ";
            cin>>ws;
            getline(cin,data);
            bool found = false;
            for(int j=0; j<countt; j++)
            {
                if(i[j].cheak(data))
                {
                    i[j].sale();
                    found = true;
                }

            }
            if(!found)
            {
                cout<<"\nItem does't exit!!!";
            }
            break;
        }
        case 4:
        {
            string data;
            cout<<"\nEnter Item ID or Name: ";
            cin>>ws;
            getline(cin,data);
            bool found = false;
            for(int j=0; j<countt; j++)
            {
                if(i[j].cheak(data))
                {
                    i[j].display();
                    found = true;
                }

            }
            if(!found)
            {
                cout<<"\nItem does't exit!!!";
            }
            break;
        }
        case 5:
            cout << "\n============= ALL ITEMS =============";
            for(int j=0; j<countt; j++)
            {
                i[j].display();
            }
            break;
        case 6:
            for(int j=0; j<countt; j++)
            {
                if(i[j].get_quantity()<5)
                {
                    cout<<"\n\n====== LOW STOCK ITEMS (Less than 5) ======";
                    i[j].display();
                    cout<<"\nlow inventory alert";
                }
            }
            break;
        case 7:
        {
            string data;
            cout<<"\nEnter Item ID or Name: ";
            cin>>ws;
            getline(cin,data);
            bool found = false;
            for(int j=0; j<countt; j++)
            {
                if(i[j].cheak(data))
                {
                    i[j].discount();
                    found = true;
                }

            }
            if(!found)
            {
                cout<<"\nItem does't exit!!!";
            }
            break;

        }
        case 8:
        {
            for(int a=0; a<countt-1; a++)
            {
                for(int b = a+1; b<countt; b++)
                {
                    if(i[a].get_quantity()>i[b].get_quantity())
                    {
                        item temp=i[a];
                        i[a] = i[b];
                        i[b] = temp;
                    }
                }
            }
            cout<<"\nItems Sorted by Quantity Successfully!";
            for(int j=0; j<countt; j++)
            {
               i[j].print_sort();
            }

        }
        break;
        case 9:
            cout<<"\nThank You for Using the System!";
            break;
        default:
            cout << "\nInvalid Choice!";

        }
    }
    while(ch!=9);
}
