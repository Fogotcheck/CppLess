#include "MyNewList.h"

MyNewList::MyNewList(const std::string &data)
	: next(nullptr)
	, data(data)
{
	std::cout << "add data:\t" << data << std::endl;
}

MyNewList::~MyNewList(void)
{
	std::cout << "rm data:\t" << data << std::endl;
}

void MyNewList::AddDataInList(const std::string &data)
{
	auto NewNode = std::make_unique<MyNewList>(data);
	MyNewList *current = this;
	while (current->next) {
		current = current->next.get();
	}
	current->next = std::move(NewNode);
}

void MyNewList::show(void)
{
	MyNewList *head = this;
	while (head) {
		std::cout << head->data << std::endl;
		head = head->next.get();
	}
}
