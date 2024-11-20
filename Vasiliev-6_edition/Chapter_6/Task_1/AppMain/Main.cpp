#include "Main.h"
#include <string>
#include "MyQueue.h"
#include "MyList.h"

using namespace std;

int main()
{
	MyQueue *QueueHead = nullptr;
	MyList *ListHead = nullptr;
	string data;
	for (size_t i = 0; i < 10; i++) {
		data = "Hello::\t" + to_string(i);
		MyQueueAddItem(QueueHead, data);
		MyListAddItem(ListHead, data);
	}
	cout << "Queue::" << endl;
	MyQueuePrintAll(QueueHead);
	cout << "List::" << endl;
	MyListPrintAll(ListHead);

	MyListRmAll(ListHead);
	MyQueueRmAll(QueueHead);
	return 0;
}
