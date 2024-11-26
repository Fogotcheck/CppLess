#include "Main.h"
using namespace std;
#include "ComplexDervid.h"

int main()
{
	ComplexDervid a(1.2, -2);
	ComplexDervid b(2.2, 4);

	ComplexDervid sum = a + b;
	cout << sum << "\tmodulus::" << sum.GetModulus()
	     << "\tcomplex conjugate number::" << sum.GetСonjugate() << endl;

	ComplexDervid tmp(1.2, -2);
	tmp.SetImag(2);

	cout << tmp << endl;

	return 0;
}
