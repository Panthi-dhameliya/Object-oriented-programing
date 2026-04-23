#include <iostream>
#include <vector>
using namespace std;

// Base class
class Shape {
public:
    virtual float area() = 0;  // pure virtual function
    virtual void display() = 0;
    virtual ~Shape() {}
};

// Rectangle class
class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float area() {
        return length * width;
    }

    void display() {
        cout << "Rectangle Area = " << area() << endl;
    }
};

// Circle class
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float area() {
        return 3.1416 * radius * radius;
    }

    void display() {
        cout << "Circle Area = " << area() << endl;
    }
};

int main() {

    // 🔹 Dynamic Storage (Vector)
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5, 3));
    shapes.push_back(new Circle(4));

    cout << "Dynamic Storage (Polymorphism):\n";
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->display();  // runtime polymorphism
    }

    // 🔹 Static Storage (Array)
    Shape* arr[2];
    arr[0] = new Rectangle(2, 6);
    arr[1] = new Circle(3);

    cout << "\nStatic Storage (Array):\n";
    for (int i = 0; i < 2; i++) {
        arr[i]->display();
    }

    // Cleanup memory
    for (int i = 0; i < shapes.size(); i++)
        delete shapes[i];

    for (int i = 0; i < 2; i++)
        delete arr[i];

    return 0;
}
