#pragma once
#include <iostream>
#include <cmath>

class ComplexBase {
    protected:
	double real;
	double imag;

    public:
	ComplexBase(double real = 0, double imag = 0);
	ComplexBase(const ComplexBase &other);

	virtual void SetReal(double real = 0);
	virtual void SetImag(double imag = 0);

	ComplexBase operator+(const ComplexBase &other) const;
	ComplexBase operator-(const ComplexBase &other) const;
	ComplexBase operator*(const ComplexBase &other) const;
	ComplexBase operator/(const ComplexBase &other) const;

	friend std::ostream &operator<<(std::ostream &os, const ComplexBase &c);
};
