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

ComplexDervid ComplexDervid::GetСonjugate(void)
{
	return ComplexBase(this->real, (this->imag * (-1)));
}
