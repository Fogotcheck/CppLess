#pragma once

#include <iostream>
#include <string>
#include <vector>

class MyNewList {
    private:
	std::unique_ptr<MyNewList> next;

    public:
	std::string data;
	void AddDataInList(const std::string &data);
	void show(void);
	MyNewList(const std::string &data);

	~MyNewList(void);
};
