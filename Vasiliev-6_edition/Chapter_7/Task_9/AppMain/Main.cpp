#include "Main.h"
#include <string>
#include "MyVector.h"

using namespace std;

int main()
{
	MyVector vecA(1, 2, 3);
	MyVector vecB(4, 5, 6);
	cout << "A=" << vecA << "\tB=" << vecB << endl;
	cout << "|A|=" << vecA.GetLen() << endl;
	cout << "A+B" << vecA + vecB << endl;
	try {
		cout << "Angle(A,B):" << vecA.GetAngle(vecA, DEGREEDS) << endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
