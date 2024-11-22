#include "Main.h"
#include <string>

#include "ComplexAlg.h"
#include "ComplexTrig.h"

using namespace std;

int main()
{
	MyComplexAlg aAlg(3, 2); // 3 + 2i
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

	MyComplexTrig aTrig(3, 2); // 3 + 2i
	MyComplexTrig bTrig(1, 7); // 1 + 7i
	std::cout << "Trig::\ta=(" << aTrig << ")\tb=(" << bTrig << ")"
		  << std::endl;
	return 0;
}
