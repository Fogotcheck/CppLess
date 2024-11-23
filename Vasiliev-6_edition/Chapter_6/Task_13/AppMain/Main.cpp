#include "Main.h"
#include <string>
#include <complex>

#include "ComplexAlg.h"
#include "ComplexTrig.h"

using namespace std;

int main()
{
	MyComplexAlg aAlg; // 3 + 2i
	aAlg.imag = 2;
	aAlg.real = 3;
	MyComplexAlg bAlg(1, 7); // 1 + 7i
	MyComplexAlg sumAlg = aAlg + bAlg;
	MyComplexAlg diffAlg = aAlg - bAlg;
	MyComplexAlg productAlg = aAlg * bAlg;
	MyComplexAlg quotientAlg;

	try {
		quotientAlg = aAlg / bAlg;
	} catch (const std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Alg::\ta=(" << aAlg << ")\tb=(" << bAlg << ")"
		  << std::endl;
	std::cout << "sum:\t\t" << sumAlg << std::endl;
	std::cout << "diff:\t\t" << diffAlg << std::endl;
	std::cout << "product:\t" << productAlg << std::endl;
	std::cout << "quotient:\t" << quotientAlg << std::endl;

	MyComplexTrig aTrig(3, 1); // 3 + 2i
	MyComplexTrig bTrig(1, 2); // 3 + 2i

	MyComplexTrig sumTrig = aTrig + bTrig;
	MyComplexTrig diffTrig = aTrig - bTrig;
	MyComplexTrig productTrig = aTrig * bTrig;
	MyComplexTrig quotientTrig;

	try {
		quotientTrig = aTrig / bTrig;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << "Trig::\ta=(" << aTrig << ")\tb=(" << bTrig << ")"
		  << std::endl;

	std::cout << "sum:\t\t" << sumTrig << std::endl;
	std::cout << "diff:\t\t" << diffTrig << std::endl;
	std::cout << "product:\t" << productTrig << std::endl;
	std::cout << "quotient:\t" << quotientTrig << std::endl;

	complex<double> aStd(3.0, 2.0);
	complex<double> bStd(1.0, 7.0);
	cout << "Complex::std::\ta=" << aStd << "\tb=" << bStd << endl;
	std::cout << "sum:\t\t" << aStd + bStd << std::endl;
	std::cout << "diff:\t\t" << aStd - bStd << std::endl;
	std::cout << "product:\t" << aStd * bStd << std::endl;
	std::cout << "quotient:\t" << aStd / bStd << std::endl;

	double modulus = 5.0;
	double angle = M_PI / 4; // 45 градусов

	// Создание комплексного числа из тригонометрической формы
	std::complex<double> z = std::polar(modulus, angle);

	cout << "z=" << z << endl;

	return 0;
}
