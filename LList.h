#pragma once
//------------------------------------------
//              class LList
//------------------------------------------
// A dynamic, unique-key, history-keeping, 
// singly Linked List
//------------------------------------------
#include "node.h"

class LList {
public:
	LList();
	~LList();
	void print();
	void insert(int k, string d);
	bool drop(int k);
	void findNode(int srchkey);
	void sort();
private:
	node * head;

	node * search(int srchKey);
	node * getb4(node * r);
	node * max();
	bool remove(node * r);
};
