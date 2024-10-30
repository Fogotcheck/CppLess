#include "Main.h"

using namespace std;

int main(void)
{
	cout << "a = arcsin((g * T)/(2 * V))" << endl;
	cout << "Input::\tV,T" << endl;
	double V = 0, T = 0;
	const double g = 9.8;
	cin >> V >> T;
	if (V == 0) {
		cout << "Div zero" << endl;
		return -1;
	}

	double tmp = (g * T) / (2 * V);
	if (abs(tmp) > 1) {
		cout << "|(" << g << " * " << T << ") / (2 * " << V
		     << ")| = " << tmp << " > 1" << endl;
		return -1;
	}

	cout << "a = arcsin((" << g << " * " << T << ")/(2 * " << V
	     << ")) = " << asin(tmp) << " rad\t" << (asin(tmp) * (180 / M_PI))
	     << " deg" << endl;
	return 0;
}
