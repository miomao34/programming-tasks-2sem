#include "complex.hpp"

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

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
    os << '{' << complex.real << ", " << complex.imag << '}';
    return os;
}

bool Complex::operator=(const Complex& complex)
{
	this->real = complex.real;
	this->imag = complex.imag;
}