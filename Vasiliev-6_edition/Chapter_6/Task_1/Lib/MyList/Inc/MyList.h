#ifndef __MyList_h__
#define __MyList_h__
#include <iostream>
#include <string>

struct MyList {
	std::string data;
	MyList *next;
};

void MyListAddItem(MyList *&head, const std::string data);
void MyListRmAll(MyList *head);
void MyListPrintAll(MyList *head);

#endif //__MyList_h__
