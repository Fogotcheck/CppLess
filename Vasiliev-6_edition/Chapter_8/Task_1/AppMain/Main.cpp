#include "Main.h"
#include "MyTree.h"
using namespace std;

int main(void)
{
	MyTree *MyTreeHead = nullptr;

	vector<string> data;
	for (size_t i = 0; i < 10; i++) {
		string tmp = "Hello::\t" + to_string(i);
		data.push_back(tmp);
	}

	try {
		MyTreeHead = new MyTree(data);
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	cout << "print" << endl;
	MyTreeHead->inOrder();
	cout << "rm" << endl;
	delete MyTreeHead;
	return 0;
}
