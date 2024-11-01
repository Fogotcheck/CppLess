#include "Main.h"

using namespace std;

int Factorial(int N, uint64_t *res);

int main(void)
{
	cout << "Cosine calculation using Taylor series\n";
	cout << "Formula: cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ... =\n";
	cout << "Please enter the value of x (in radians) and N (for factorial):\n";

	double x = 0;
	int N = 0;
	uint64_t FactorialRes = 0;
	double CosineRes = 1;
	bool sign = 1;

	cin >> x >> N;
	if (N < 0) {
		return -1;
	}

	for (int i = 2; i <= N; i += 2) {
		if (Factorial(i, &FactorialRes)) {
			break;
		}
		if (sign) {
			CosineRes -= (pow(x, i) / FactorialRes);
		} else {
			CosineRes += (pow(x, i) / FactorialRes);
		}
		sign ^= 1;
	}
	cout << fixed << setprecision(6);
	cout << "cos(x) = 1 - " << x << "^2/2! + " << x << "^4/4! - " << x
	     << "^6/6! + ... = " << CosineRes << endl;

	cout << "Check cmath::\t" << cos(x) << endl;
	return 0;
}

int Factorial(int N, uint64_t *res)
{
	if (N < 0) {
		cout << "Factorial is not defined for negative numbers."
		     << endl;
		return -1;
	}

	*res = 1;
	for (int i = 1; i <= N; ++i) {
		if (*res > numeric_limits<uint64_t>::max() / i) {
			cout << "Overflow occurred when multiplying by " << i
			     << endl;
			return -1;
		}
		*res *= i;
	}

	return 0;
}
