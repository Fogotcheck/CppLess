#include "MyQueue.h"

static MyQueue *MyQueueGetTail(MyQueue *head)
{
	if (!head)
		return nullptr;

	MyQueue *tail = head;
	while (tail->next) {
		tail = tail->next;
	}
	return tail;
}

void MyQueueAddItem(MyQueue *&head, const std::string data)
{
	MyQueue *Item = nullptr;
	MyQueue *tail = nullptr;
	try {
		Item = new MyQueue;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		return;
	}
	Item->data = data;
	Item->next = nullptr;

	if (head) {
		tail = MyQueueGetTail(head);
	} else {
		head = Item;
		return;
	}

	tail->next = Item;
}

void MyQueueRmAll(MyQueue *head)
{
	while (head) {
		MyQueue *tmp = head;
		head = head->next;
		try {
			delete tmp;
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
	}
}

void MyQueuePrintAll(MyQueue *head)
{
	while (head) {
		std::cout << head->data << std::endl;
		head = head->next;
	}
}
