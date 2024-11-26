#include "ComplexDervid.h"

ComplexDervid::ComplexDervid(double real, double imag)
	: ComplexBase(real, imag)
{
}

ComplexDervid::ComplexDervid(const ComplexBase &other)
	: ComplexBase(other)
{
}

double ComplexDervid::GetModulus(void)
{
	return sqrt(this->real * this->real + this->imag * this->imag);
}

ComplexBase ComplexDervid::GetСonjugate(void)
{
	return ComplexBase(this->real, (this->imag * (-1)));
}

void ComplexDervid::SetReal(double real, double base)
{
	this->real = real + base;
}
void ComplexDervid::SetImag(double imag, double base)
{
	this->imag = imag + base;
}
