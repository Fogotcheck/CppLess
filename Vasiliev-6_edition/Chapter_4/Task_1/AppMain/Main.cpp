#include "Main.h"

using namespace std;

uint64_t fibonacci(int n);

int main(void)
{
	cout << "Program with the function of calculating a number from the Fibonacci sequence. "
	     << endl
	     << "The function argument is ordinal number of numbers in sequence "
	     << endl;
	int Num = 0;
	cin >> Num;
	try {
		uint64_t result = fibonacci(Num);
		cout << "Fibonacci number with serial number " << Num << " = "
		     << result << endl;
	} catch (const invalid_argument &e) {
		cerr << "Errors: " << e.what() << endl;
	}
	return 0;
}

uint64_t fibonacci(int n)
{
	if (n < 0) {
		throw invalid_argument(
			"The sequence number cannot be negative.");
	}
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
