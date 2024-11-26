#pragma once
#include <iostream>
#include <cmath>

class ComplexBase {
    public:
	double real;
	double imag;
	ComplexBase(double real = 0, double imag = 0);
	ComplexBase(const ComplexBase &other);
	ComplexBase operator+(const ComplexBase &other) const;
	ComplexBase operator-(const ComplexBase &other) const;
	ComplexBase operator*(const ComplexBase &other) const;
	ComplexBase operator/(const ComplexBase &other) const;

	friend std::ostream &operator<<(std::ostream &os, const ComplexBase &c);
};
