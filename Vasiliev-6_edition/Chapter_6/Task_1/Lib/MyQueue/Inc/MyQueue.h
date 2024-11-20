#ifndef __MyQueue_h__
#define __MyQueue_h__
#include <iostream>
#include <string>

struct MyQueue {
	std::string data;
	MyQueue *next;
};

void MyQueueAddItem(MyQueue *&head, const std::string data);
void MyQueueRmAll(MyQueue *head);
void MyQueuePrintAll(MyQueue *head);
#endif //__MyQueue_h__
