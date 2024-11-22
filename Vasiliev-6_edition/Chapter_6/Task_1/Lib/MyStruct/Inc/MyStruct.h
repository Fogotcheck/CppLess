#ifndef __MyStruct_h__
#define __MyStruct_h__
#include <iostream>
#include <string>

enum MyStructLevel {
	SUB_HEAD_LEVEL,
	SAME_LEVEL,
};

struct MyStruct {
	std::string data;
	int level;
	MyStruct *right;
	MyStruct *left;
};

void MyStructAddItem(MyStruct *&head, int level, const std::string data);
void MyStructRmAll(MyStruct *head);
void MyStructPrintAll(MyStruct *head);

#endif //__MyStruct_h__
