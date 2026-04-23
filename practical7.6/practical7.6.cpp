#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {
        cout << "Base Destructor Called\n";
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[5];  // dynamic allocation
        cout << "Derived Constructor Called\n";
    }

    ~Derived() {
        delete[] data;  // resource release
        cout << "Derived Destructor Called\n";
    }
};

int main() {
    Base* ptr = new Derived();  // base pointer to derived object

    delete ptr;  // ❌ Only Base destructor will be called

    return 0;
}
