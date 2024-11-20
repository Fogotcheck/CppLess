#include "MyList.h"

void MyListAddItem(MyList *&head, const std::string data)
{
	MyList *Item = nullptr;
	try {
		Item = new MyList;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		return;
	}
	Item->data = data;
	Item->next = head;
	head = Item;
}

void MyListRmAll(MyList *head)
{
	while (head) {
		MyList *tmp = head;
		head = head->next;
		try {
			delete tmp;
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
	}
}

void MyListPrintAll(MyList *head)
{
	while (head) {
		std::cout << head->data << std::endl;
		head = head->next;
	}
}
