#include "MyTree.h"

MyTree::MyTree(const std::vector<std::string> &data)
	: left(nullptr)
	, right(nullptr)
{
	MyTree *Last = this;

	this->data = data[0];
	for (size_t i = 1; i < data.size(); i++) {
		std::cout << data[i] << std::endl;

		std::vector<std::string> tmp = { data[i] };
		MyTree *Item = new MyTree(tmp);
		MyTree *left = Last->left;
		MyTree *right = Last->right;
		if (left == nullptr) {
			Last->left = Item;
		} else {
			Last->right = Item;
			if ((Last->left) && (Last->right)) {
				Last = Last->left;
			}
		}
	}
}

void MyTree::inOrder() const
{
	if (left)
		left->inOrder();
	std::cout << data << "\t";
	if (right)
		right->inOrder();
}

MyTree::~MyTree()
{
	if (left) {
		std::cout << "Rm:Left::\t" << left->data << std::endl;
		delete left;
	}
	if (right) {
		std::cout << "Rm:right::\t" << right->data << std::endl;
		delete right;
	}
}
