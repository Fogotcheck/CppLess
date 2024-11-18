#include "Main.h"
#include <limits>

using namespace std;
#define VECTOR_ARRAY_COUNT 3

int DotProductVectors(double *a, double *b, double *res);
int CalcVectorModulus(double *a, double *res);

int main(void)
{
	cout << "Program to calculate the angle ϕ between vectors. "
	     << "The components of the vectors are entered by the user."
	     << endl;
	double VectorA[VECTOR_ARRAY_COUNT] = { 0 },
	       VectorB[VECTOR_ARRAY_COUNT] = { 0 };
	cout << "Vector a::" << endl;
	for (uint8_t i = 0; i < sizeof(VectorA) / sizeof(VectorA[0]); i++) {
		cin >> VectorA[i];
	}
	cout << "Vector b::" << endl;
	for (uint8_t i = 0; i < sizeof(VectorB) / sizeof(VectorB[0]); i++) {
		cin >> VectorB[i];
	}
	double Res = 0, DotProduct = 0, ModuleA = 0, ModuleB = 0;
	if (DotProductVectors(VectorA, VectorB, &DotProduct)) {
		return -1;
	}
	cout << "DotProduct::\t" << DotProduct << endl;
	if ((CalcVectorModulus(VectorA, &ModuleA)) ||
	    (CalcVectorModulus(VectorB, &ModuleB))) {
		return -1;
	}
	cout << "ModuleA::\t" << ModuleA << endl
	     << "ModuleB::\t" << ModuleB << endl;

	if ((ModuleA == 0) || (ModuleB == 0)) {
		cout << "Dev zero" << endl;
		return -1;
	}

	Res = acos(DotProduct / (ModuleA * ModuleB));
	cout << "angle(rad)::\t" << Res << "\t(degrees)::\t"
	     << (Res * (180.0 / M_PI)) << endl;
	return 0;
}

int DotProductVectors(double *a, double *b, double *res)
{
	*res = 0;
	for (size_t i = 0; i < VECTOR_ARRAY_COUNT; i++) {
		if (((long double)(*res + a[i] * b[i])) >
		    numeric_limits<double>::max()) {
			*res = 0;
			cout << "Value too large, may cause overflow!" << endl;
			return -1;
		}

		*res += a[i] * b[i];
	}
	return 0;
}

int CalcVectorModulus(double *a, double *res)
{
	for (size_t i = 0; i < VECTOR_ARRAY_COUNT; i++) {
		if (((long double)(*res + a[i] * a[i])) >=
		    numeric_limits<double>::max()) {
			cout << "Value too large, may cause overflow!" << endl;
			return -1;
		}
		*res += a[i] * a[i];
	}
	*res = sqrt(*res);
	return 0;
}
