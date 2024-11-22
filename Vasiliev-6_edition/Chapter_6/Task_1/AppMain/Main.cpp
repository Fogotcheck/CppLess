#include "Main.h"
#include <string>
#include "MyQueue.h"
#include "MyList.h"
#include "MyStruct.h"

using namespace std;

int main()
{
	MyQueue *QueueHead = nullptr;
	MyList *ListHead = nullptr;
	MyStruct *MyStructHead = nullptr;
	string data;
	for (size_t i = 0; i < 10; i++) {
		data = "Hello::\t" + to_string(i);
		MyQueueAddItem(QueueHead, data);
		MyListAddItem(ListHead, data);
		MyStructAddItem(MyStructHead, SAME_LEVEL, data);
	}
	cout << "Queue::" << endl;
	MyQueuePrintAll(QueueHead);
	cout << "List::" << endl;
	MyListPrintAll(ListHead);
	cout << "MyStruct" << endl;
	for (size_t i = 10; i < 20; i++) {
		data = "Hello::\t" + to_string(i);
		MyStructAddItem(MyStructHead, SUB_HEAD_LEVEL, data);
	}
	for (size_t i = 20; i < 50; i++) {
		data = "Hello::\t" + to_string(i);
		MyStructAddItem(MyStructHead, SAME_LEVEL, data);
	}
	for (size_t i = 50; i < 80; i++) {
		data = "Hello::\t" + to_string(i);
		if (i % 4) {
			MyStructAddItem(MyStructHead, SUB_HEAD_LEVEL, data);
		} else {
			MyStructAddItem(MyStructHead, SAME_LEVEL, data);
		}
	}

	MyStructPrintAll(MyStructHead);

	MyListRmAll(ListHead);
	MyQueueRmAll(QueueHead);
	MyStructRmAll(MyStructHead);
	return 0;
}
