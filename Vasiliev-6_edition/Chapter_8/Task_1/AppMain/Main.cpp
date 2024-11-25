#include "Main.h"
#include "MyNewList.h"

using namespace std;

std::unique_ptr<MyNewList> test(void)
{
	vector<string> data = { "Hello::0" };
	auto MyHead = make_unique<MyNewList>(data[0]);
	for (size_t i = 1; i < 10; i++) {
		string tmp = "Hello::\t" + to_string(i);
		data.push_back(tmp);
		MyHead->AddDataInList(tmp);
	}
	MyHead->show();

	return MyHead;
}
int main(void)
{
	auto MyHead = test();
	MyHead->show();
	return 0;
}
