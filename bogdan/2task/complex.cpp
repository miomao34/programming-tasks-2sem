#include "complex.hpp"

using namespace std;

Complex::Complex()
{
	this->real = 0;
	this->imag = 0;
}

Complex::Complex(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

ostream& operator<<(ostream& os, const Complex& complex)
{
    os << '{' << complex.real << ", " << complex.imag << '}';
    return os;
}

bool Complex::operator=(const Complex& complex)
{
	this->real = complex.real;
	this->imag = complex.imag;
}