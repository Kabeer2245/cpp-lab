#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r=0.0, double i=0.0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator-() const{
        return Complex(-real, -imag);
    }

    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        ++(*this);
        return temp;
    }

    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex a(2.0, 5.0);
    Complex b(3.0, 7.0);

    Complex c=a+b;
    Complex d=a-b;
    Complex e=-a;
    Complex f=++a;
    Complex g=b++;
    a+=b;

    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    cout<<"d: "<<d<<endl;
    cout<<"e: "<<e<<endl;
    cout<<"f: "<<f<<endl;
    cout<<"g: "<<g<<endl;

    return 0;
}