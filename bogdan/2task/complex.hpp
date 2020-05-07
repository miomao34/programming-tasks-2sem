#pragma once

#include <iostream>

class Complex
{
private:
	double real;
	double imag;
public:
	Complex();
	Complex(double real, double imag);

	friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
	bool operator=(const Complex& complex);
};