#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit; // forward declaration

class Celsius {
private:
    float temp;

public:
    Celsius(float t = 0) { temp = t; }

    float getTemp() const { return temp; }

    // Conversion: Celsius → Fahrenheit
    operator Fahrenheit();

    // Equality operator
    bool operator == (const Celsius& c) {
        return temp == c.temp;
    }
};

class Fahrenheit {
private:
    float temp;

public:
    Fahrenheit(float t = 0) { temp = t; }

    float getTemp() const { return temp; }

    // Conversion: Fahrenheit → Celsius
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    // Equality operator
    bool operator == (const Fahrenheit& f) {
        return temp == f.temp;
    }
};

// Define Celsius → Fahrenheit conversion
Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main() {
    // Basic conversion
    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;  // implicit conversion
    cout << "25 Celsius in Fahrenheit = " << f1.getTemp() << endl;

    // Reverse conversion
    Fahrenheit f2(98.6);
    Celsius c2 = f2;
    cout << "98.6 Fahrenheit in Celsius = " << c2.getTemp() << endl;

    // Equality check
    Celsius c3(25);
    if (c1 == c3)
        cout << "Temperatures are equal (Celsius)" << endl;

    // 🔹 Queue (Dynamic Storage)
    queue<Fahrenheit> q;
    q.push(c1);  // auto conversion

    cout << "\nQueue Processing (FIFO):\n";
    while (!q.empty()) {
        cout << q.front().getTemp() << " F" << endl;
        q.pop();
    }

    // 🔹 Array (Static Storage)
    Celsius arr[3] = { Celsius(0), Celsius(100), Celsius(37) };

    cout << "\nArray Storage (Celsius to Fahrenheit):\n";
    for (int i = 0; i < 3; i++) {
        Fahrenheit tempF = arr[i];
        cout << arr[i].getTemp() << " C = "
             << tempF.getTemp() << " F" << endl;
    }

    return 0;
}
