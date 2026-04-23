#include<iostream>
using namespace std;
class point
{
private:
    int x,y;
public:
    point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    point& move(int dx,int dy)
    {
        x+=dx;
        y+=dy;
        return *this;
    }
    void display()
    {
         cout << "(" << x << ", " << y << ")" << endl;
    }
};
int main()
{
    point p(1,2);
    p.move(2,3).move(-1,4);
    p.display();
}
