#include "ComplexAlg.h"

// Реализация конструктора
MyComplexAlg::MyComplexAlg(double real, double imag)
	: real(real)
	, imag(imag)
{
}

// Реализация оператора сложения
MyComplexAlg MyComplexAlg::operator+(const MyComplexAlg &other) const
{
	return MyComplexAlg(real + other.real, imag + other.imag);
}

// Реализация оператора вычитания
MyComplexAlg MyComplexAlg::operator-(const MyComplexAlg &other) const
{
	return MyComplexAlg(real - other.real, imag - other.imag);
}

// Реализация оператора умножения
MyComplexAlg MyComplexAlg::operator*(const MyComplexAlg &other) const
{
	return MyComplexAlg(real * other.real - imag * other.imag,
			    real * other.imag + imag * other.real);
}

// Реализация оператора деления
MyComplexAlg MyComplexAlg::operator/(const MyComplexAlg &other) const
{
	double denominator = other.real * other.real + other.imag * other.imag;
	if (denominator == 0) {
		throw std::invalid_argument("Division by zero");
	}
	return MyComplexAlg(
		(real * other.real + imag * other.imag) / denominator,
		(imag * other.real - real * other.imag) / denominator);
}

// Реализация перегрузки оператора вывода
std::ostream &operator<<(std::ostream &os, const MyComplexAlg &c)
{
	os << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag)
	   << "i";
	return os;
}
