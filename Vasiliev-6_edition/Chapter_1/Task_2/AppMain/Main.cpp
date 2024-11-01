#include "Main.h"

using namespace std;

int main(void)
{
	cout << "Distance calculation for projectile motion\n";
	cout << "Formula: L = (V^2 * sin(2a)) / g\n";
	cout << "Please enter initial speed (V) in m/s and angle (a) in degrees:\n";

	double V = 0, Alpha = 0;
	const double g = 9.8;

	cin >> V >> Alpha;

	cout << fixed << setprecision(4);

	cout << "L = (" << V << "^2 * sin(2* " << Alpha << ")) / " << g << " = "
	     << (V * V * sin(2 * (Alpha * M_PI / 180))) / g << endl;

	return 0;
}
