#include "Main.h"

using namespace std;

int main(void)
{
	cout << "Program for calculating the flight time of a body thrown at an angle to the horizontal."
	     << endl;
	cout << "Please enter the value of V and alpha (in deg)\n";

	const double g = 9.8, dt = 0.0001;
	double V = 0, a = 0, v = 0, u = 0, x = 0, y = 0;
	double t = 0;

	cin >> V >> a;
	if ((a < 0) || (a > 90)) {
		return -1;
	}

	a = a * M_PI / 180;

	v = V * cos(a);
	u = V * sin(a);
	do {
		y += u * dt;
		x += v * dt;
		u -= g * dt;
		t += dt;
	} while (y > 0);
	cout << "y = " << y << " : ";
	cout << (t < sqrt(2 * V * sin(a) / g) ? V * sin(a) * t - g * t * t / 2 :
						0)
	     << endl;
	cout << "x = " << x << " : ";
	cout << (t < sqrt(2 * V * sin(a) / g) ? V * cos(a) * t :
						V * V * sin(2 * a) / g)
	     << endl;
	cout << "t = " << t << endl;
	return 0;
}
