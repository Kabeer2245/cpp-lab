#include <iostream>
using namespace std;

void print(int x) {
    cout<<"Printing integer: "<<x<<endl;
}

void print(double x) {
    cout<<"Printing double: "<<x<<endl;
}

class Base {
public:
    virtual void display(){
        cout<<"Base display function\n";
    }
};

class Derived : public Base {
public:
    void display() override {
        cout<<"Derived display function\n";
    }
};

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    friend::ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};


int main() {
    print(5);
    print(3.14);

    Base baseObj;
    Derived derivedObj;

    baseObj.display();
    derivedObj.display();

    Base* ptr = new Derived();
    ptr->display();

    delete ptr;

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    cout<<"Sum of c1 and c2 is: " << c3 << endl;

    return 0;
}