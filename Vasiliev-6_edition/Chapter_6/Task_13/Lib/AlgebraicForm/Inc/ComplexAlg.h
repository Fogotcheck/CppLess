#ifndef __ComplexAlg_h__
#define __ComplexAlg_h__
#include <iostream>
#include <cmath>

struct MyComplexAlg {
	double real, imag;
	explicit MyComplexAlg(double r = 0, double i = 0);
	// Перегрузка операторов
	MyComplexAlg operator+(const MyComplexAlg &other) const;
	MyComplexAlg operator-(const MyComplexAlg &other) const;
	MyComplexAlg operator*(const MyComplexAlg &other) const;
	MyComplexAlg operator/(const MyComplexAlg &other) const;
	// Перегрузка оператора вывода
	friend std::ostream &operator<<(std::ostream &os,
					const MyComplexAlg &c);
};

#endif //__ComplexAlg_h__
