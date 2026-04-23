#include <iostream>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter numerator and denominator: ";

        // Input extraction with validation
        if (!(cin >> a >> b)) {
            throw "Invalid input! Please enter integers only.";
        }

        // Division check immediately
        if (b == 0) {
            throw "Error: Division by zero is not allowed.";
        }

        // Perform division
        cout << "Result = " << (a / b) << endl;
    }

    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}
