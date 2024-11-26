#include "ComplexBase.h"

ComplexBase::ComplexBase(double real, double imag)
	: real(real)
	, imag(imag)
{
}
ComplexBase::ComplexBase(const ComplexBase &other)
{
	*this = other;
}

ComplexBase ComplexBase::operator+(const ComplexBase &other) const
{
	return ComplexBase(real + other.real, imag + other.imag);
}
ComplexBase ComplexBase::operator-(const ComplexBase &other) const
{
	return ComplexBase(real - other.real, imag - other.imag);
}
ComplexBase ComplexBase::operator*(const ComplexBase &other) const
{
	return ComplexBase(real * other.real - imag * other.imag,
			   real * other.imag + imag * other.real);
}
ComplexBase ComplexBase::operator/(const ComplexBase &other) const
{
	double denominator = other.real * other.real + other.imag * other.imag;
	if (denominator == 0) {
		throw std::invalid_argument("Division by zero");
	}
	return ComplexBase(
		(real * other.real + imag * other.imag) / denominator,
		(imag * other.real - real * other.imag) / denominator);
}

std::ostream &operator<<(std::ostream &os, const ComplexBase &c)
{
	os << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag)
	   << "i)";
	return os;
}
