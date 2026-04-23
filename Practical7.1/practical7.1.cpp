#include <iostream>
using namespace std;

class Calculator {
private:
    float results[10];  // store results
    int index;

public:
    Calculator() {
        index = 0;
    }

    // add two integers
    int add(int a, int b) {
        int result = a + b;
        results[index++] = result;
        return result;
    }

    // add two floats
    float add(float a, float b) {
        float result = a + b;
        results[index++] = result;
        return result;
    }

    // add int and float
    float add(int a, float b) {
        float result = a + b;
        results[index++] = result;
        return result;
    }

    // display all results
    void displayResults() {
        cout << "\nStored Results:\n";
        for (int i = 0; i < index; i++) {
            cout << "Result " << i + 1 << " = " << results[i] << endl;
        }
    }
};

int main() {
    Calculator calc;

    cout << "Addition of integers: " << calc.add(5, 10) << endl;
    cout << "Addition of floats: " << calc.add(2.5f, 3.5f) << endl;
    cout << "Addition of int & float: " << calc.add(7, 4.2f) << endl;

    calc.displayResults();

    return 0;
}
