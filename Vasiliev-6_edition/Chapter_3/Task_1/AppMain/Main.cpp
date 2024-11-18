#include "Main.h"
#include <limits>

using namespace std;
#define VECTOR_ARRAY_COUNT 3

int main(void)
{
	cout << "Program for calculating the vector modulus."
	     << " The vector components are entered by the user." << endl;
	double vector_a[VECTOR_ARRAY_COUNT] = { 0 };
	for (uint8_t i = 0; i < (sizeof(vector_a) / sizeof(vector_a[0])); i++) {
		cin >> vector_a[i];
	}

	long double res = 0;
	for (size_t i = 0; i < (sizeof(vector_a) / sizeof(vector_a[0])); i++) {
		res += vector_a[i] * vector_a[i];
		if (res >= numeric_limits<double>::max()) {
			cout << "Value too large, may cause overflow!" << endl;
			return 1;
		}

		cout << vector_a[i] << "\t" << res << endl;
	}
	res = sqrt(res);
	cout << "res::" << res << endl;
	return 0;
}
