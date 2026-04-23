#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructor
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator + (const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload - operator
    Complex operator - (const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Display function
    void display() {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "\nSecond Complex Number: ";
    c2.display();

    cout << "\n\nAddition Result: ";
    sum.display();

    cout << "\nSubtraction Result: ";
    diff.display();

    return 0;
}
