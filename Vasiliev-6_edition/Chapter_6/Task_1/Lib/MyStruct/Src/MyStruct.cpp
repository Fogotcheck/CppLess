#include "MyStruct.h"

static void MyStructGetNext(MyStruct *head, int &level, MyStruct *&tail)
{
	MyStruct *Left = head;
	MyStruct *Right = head;

	size_t LeftCount = 0;
	size_t RightCount = 0;

	while (Left->left) {
		LeftCount++;
		Left = Left->left;
	}

	while (Right->right) {
		RightCount++;
		Right = Right->right;
	}

	try {
		tail = new MyStruct;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
		return;
	}

	if (LeftCount > RightCount) {
		tail->right = nullptr;
		tail->left = Left;
		Left->right = tail;
		Right->right = tail;
		level = SAME_LEVEL;
	} else {
		tail->left = nullptr;
		tail->right = nullptr;
		Left->left = tail;
		if (level == SUB_HEAD_LEVEL) {
			Right->right = tail;
		}
	}
}

void MyStructAddItem(MyStruct *&head, int level, const std::string data)
{
	MyStruct *Item = nullptr;
	MyStruct *tail = nullptr;
	if (head == nullptr) {
		try {
			head = new MyStruct;
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
			return;
		}
		head->data = data;
		head->level = SUB_HEAD_LEVEL;
		head->left = nullptr;
		head->right = nullptr;
		return;
	}
	MyStructGetNext(head, level, tail);
	if (tail == nullptr) {
		throw std::logic_error("Err::\talloc mem:\t\"new==nullptr\"");
	}
	tail->data = data;
	tail->level = level;
}

void MyStructRmAll(MyStruct *head)
{
	if (head == nullptr) {
		return;
	}

	MyStruct *Left = head->left;
	while (Left) {
		MyStruct *tmp = Left;
		Left = Left->left;

		if (tmp->level == SUB_HEAD_LEVEL) {
			MyStructRmAll(tmp);
			break;
		}

		if (tmp->right) {
			// std::cout << tmp->right->data << std::endl;
			try {
				delete tmp->right;
			} catch (const std::exception &e) {
				std::cerr << e.what() << '\n';
			}
		}

		try {
			// std::cout << tmp->data << std::endl;
			delete tmp;
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
	}

	try {
		// std::cout << head->data << std::endl;
		delete head;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
}

void MyStructPrintAll(MyStruct *head)
{
	if (head == nullptr) {
		return;
	}
	std::cout << "\tlevel:[" << head->level << "]::" << head->data
		  << std::endl;
	MyStruct *Left = head->left;
	while (Left) {
		MyStruct *tmp = Left;
		Left = Left->left;
		if (tmp->level == SUB_HEAD_LEVEL) {
			MyStructPrintAll(tmp);
			break;
		}

		std::cout << "level:[" << tmp->level << "]::" << tmp->data
			  << "\t";
		if (tmp->right) {
			std::cout << "level:[" << tmp->right->level
				  << "]::" << tmp->right->data;
		}
		std::cout << std::endl;
	}
}
