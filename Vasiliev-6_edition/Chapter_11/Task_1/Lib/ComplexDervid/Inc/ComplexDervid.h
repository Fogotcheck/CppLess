#pragma once
#include "ComplexBase.h"

class ComplexDervid : public ComplexBase {
    public:
	ComplexDervid(double real, double imag);
	ComplexDervid(const ComplexBase &other);
	double GetModulus(void);
	ComplexBase GetСonjugate(void);
};
