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

    // --- Member functions ---
    // Addition
    Complex operator + (Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator - (Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // --- Friend functions ---
    friend Complex operator * (Complex c1, Complex c2);
    friend Complex operator / (Complex c1, Complex c2);

    // Display function
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Multiplication using friend function
Complex operator * (Complex c1, Complex c2) {
    return Complex((c1.real * c2.real - c1.imag * c2.imag),
                   (c1.real * c2.imag + c1.imag * c2.real));
}

// Division using friend function
Complex operator / (Complex c1, Complex c2) {
    float denom = c2.real * c2.real + c2.imag * c2.imag;
    return Complex(((c1.real * c2.real + c1.imag * c2.imag) / denom),
                   ((c1.imag * c2.real - c1.real * c2.imag) / denom));
}

int main() {
    Complex c1(6, 4), c2(2, 2);

    Complex sum = c1 + c2;   // Member function
    Complex diff = c1 - c2;  // Member function
    Complex prod = c1 * c2;  // Friend function
    Complex div = c1 / c2;   // Friend function

    cout << "First Complex Number: ";
    c1.display();
    cout << "Second Complex Number: ";
    c2.display();

    cout << "\nSum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    cout << "Product: ";
    prod.display();

    cout << "Division: ";
    div.display();

    return 0;
}
