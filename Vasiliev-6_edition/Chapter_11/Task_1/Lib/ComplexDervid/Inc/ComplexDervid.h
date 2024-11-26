#pragma once
#include "ComplexBase.h"

class ComplexDervid : public ComplexBase {
    public:
	ComplexDervid(double real, double imag);
	ComplexDervid(const ComplexBase &other);

	virtual void SetReal(double real, double offset = 0);
	virtual void SetImag(double imag, double offset = 0);

	double GetModulus(void);
	ComplexBase GetСonjugate(void);
};
