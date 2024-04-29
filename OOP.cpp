#include <iostream>
using namespace std;

class Shape { // base class
protected:
    int width, height;
public:
    Shape(int w, int h) : width(w), height(h) {} // constructor
    virtual ~Shape() {} // virtual destructor
    virtual double area() const = 0; // pure virtual function 
    friend ostream& operator<<(ostream& os, const Shape& shape); // friend function declaration
};

class Rectangle  : public Shape { // derived class 1
public:
    Rectangle(int w, int h) : Shape(w, h) {}
    double area() const override { // override area calculation for rectangle
        return width * height;
    }
};

class Triangle  : public Shape { // derived class 2
public:
    Triangle(int w, int h) : Shape(w, h) {}
    double area() const override { // override area calculation for triangle
        return 0.5 * width * height;
    }
};

ostream& operator<<(ostream& os, const Shape& shape) { // friend function definition
    os << "Area: " << shape.area();
    return os;
}

int main() {
// objects of derived classes
    Rectangle rectangle(5, 4);
    Triangle triangle(3, 6);

// polymorphism : using base class pointer to point to derived class objects
    Shape* ptr1 = &rectangle;
    Shape* ptr2 = &triangle;

// accessing area through polymorphism
    cout << "Rectangle " << *ptr1 << endl;
    cout << "Triangle " << *ptr2 << endl;

    return 0;
}