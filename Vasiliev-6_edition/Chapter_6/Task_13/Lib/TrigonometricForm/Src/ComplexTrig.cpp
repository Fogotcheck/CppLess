#include "ComplexTrig.h"

MyComplexTrig::MyComplexTrig(double real, double phi)
{
	this->phi = phi;
	this->modulus = std::sqrt(real * real + (real * std::tan(phi)) *
							(real * std::tan(phi)));
}

MyComplexTrig MyComplexTrig::operator+(const MyComplexTrig &other) const
{
	double r1 = modulus * std::cos(phi);
	double i1 = modulus * std::sin(phi);
	double r2 = other.modulus * std::cos(other.phi);
	double i2 = other.modulus * std::sin(other.phi);

	return MyComplexTrig(r1 + r2, std::atan2(i1 + i2, r1 + r2));
}

MyComplexTrig MyComplexTrig::operator-(const MyComplexTrig &other) const
{
	double r1 = modulus * std::cos(phi);
	double i1 = modulus * std::sin(phi);
	double r2 = other.modulus * std::cos(other.phi);
	double i2 = other.modulus * std::sin(other.phi);

	return MyComplexTrig(r1 - r2, std::atan2(i1 - i2, r1 - r2));
}

MyComplexTrig MyComplexTrig::operator*(const MyComplexTrig &other) const
{
	return MyComplexTrig(modulus * other.modulus, phi + other.phi);
}

MyComplexTrig MyComplexTrig::operator/(const MyComplexTrig &other) const
{
	if (other.modulus == 0) {
		throw std::invalid_argument("Division by zero");
	}
	return MyComplexTrig(modulus / other.modulus, phi - other.phi);
}

std::ostream &operator<<(std::ostream &os, const MyComplexTrig &c)
{
	os << c.modulus << "(cos(" << c.phi << ") + i*sin(" << c.phi << "))";
	return os;
}
