#ifndef __ComplexTrig_h__
#define __ComplexTrig_h__

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

struct MyComplexTrig {
	double modulus, phi;
	explicit MyComplexTrig(double real = 0, double phi = 0);
	MyComplexTrig operator+(const MyComplexTrig &other) const;
	MyComplexTrig operator-(const MyComplexTrig &other) const;
	MyComplexTrig operator*(const MyComplexTrig &other) const;
	MyComplexTrig operator/(const MyComplexTrig &other) const;
	friend std::ostream &operator<<(std::ostream &os,
					const MyComplexTrig &c);
};

#endif //__ComplexTrig_h__
