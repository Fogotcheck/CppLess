#ifndef __ComplexTrig_h__
#define __ComplexTrig_h__
#include <iostream>
#include <cmath>

struct MyComplexTrig {
	double real, phi;
	explicit MyComplexTrig(double r = 0, double phi = 0);
	MyComplexTrig operator+(const MyComplexTrig &other) const;
	MyComplexTrig operator-(const MyComplexTrig &other) const;
	MyComplexTrig operator*(const MyComplexTrig &other) const;
	MyComplexTrig operator/(const MyComplexTrig &other) const;

	friend std::ostream &operator<<(std::ostream &os,
					const MyComplexTrig &c);
};

#endif //__ComplexTrig_h__
