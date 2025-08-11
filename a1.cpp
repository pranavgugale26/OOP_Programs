#include <iostream>
using namespace std;

class Complex 
{
	private:
    	double real, imag;

	public:
	    // Default Constructor
	    Complex() : real(0), imag(0) {}
	
	    // Parameterized Constructor
	    Complex(double r, double i) : real(r), imag(i) {}
	
	    // Overload + operator to add two complex numbers
	    Complex operator+(const Complex &other) 
		{
	        return Complex(real + other.real, imag + other.imag);
	    }
	
	    // Overload * operator to multiply two complex numbers
	    Complex operator*(const Complex &other) 
		{
	        return Complex((real * other.real - imag * other.imag), (real * other.imag + imag * other.real));
	    }
	
	    // Overload << operator for output
	    friend ostream &operator<<(ostream &out, const Complex &c) 
		{
	        if (c.imag >= 0)
	            out << c.real << "+" << c.imag << "i";
	        else
	            out << c.real << "-" << -c.imag << "i";
	        return out;
	    }

	    // Overload >> operator for input
	    friend istream &operator>>(istream &in, Complex &c) 
		{
	        cout << "Enter real part: ";
	        in >> c.real;
	        cout << "Enter imaginary part: ";
	        in >> c.imag;
	        return in;
	    }
};

int main() 
{
    Complex c1, c2, c3, c4;

    // Input two complex numbers
    cout << "Enter the first complex number:" << endl;
    cin >> c1;
    cout << "Enter the second complex number:" << endl;
    cin >> c2;

    // Add the complex numbers
    c3 = c1 + c2;
    cout << "Addition: " << c3 << endl;

    // Multiply the complex numbers
    c4 = c1 * c2;
    cout << "Multiplication: " << c4 << endl;

    return 0;
}

