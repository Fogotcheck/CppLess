#include "ComplexTrig.h"

MyComplexTrig::MyComplexTrig(double real, double phi)
{
	// @todo add check
	this->real = real;
	this->phi = phi;
}

MyComplexTrig MyComplexTrig::operator+(const MyComplexTrig &other) const
{
	MyComplexTrig stab;
	return stab;
}

MyComplexTrig MyComplexTrig::operator-(const MyComplexTrig &other) const
{
	MyComplexTrig stab;
	return stab;
}

MyComplexTrig MyComplexTrig::operator*(const MyComplexTrig &other) const
{
	MyComplexTrig stab;
	return stab;
}

MyComplexTrig MyComplexTrig::operator/(const MyComplexTrig &other) const
{
	MyComplexTrig stab;
	return stab;
}

std::ostream &operator<<(std::ostream &os, const MyComplexTrig &c)
{
	os << c.real << "(cos(phi)" << (c.phi > 0 ? "+" : "-") << c.phi
	   << "sin(phi)";
	return os;
}
