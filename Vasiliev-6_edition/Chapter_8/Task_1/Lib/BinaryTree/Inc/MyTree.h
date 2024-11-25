#pragma once
#include <iostream>
#include <string>
#include <vector>

class MyTree {
    private:
	std::string data;
	MyTree *left;
	MyTree *right;

    public:
	void inOrder() const;
	MyTree(const std::vector<std::string> &data);
	~MyTree();
};
