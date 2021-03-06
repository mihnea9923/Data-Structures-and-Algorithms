#pragma once
#include "Libs.h"
class LinkedListNode
{
public:
	int value;
	LinkedListNode* next;
	LinkedListNode(int value)
	{
		this->value = value;
		next = NULL;
	}
	LinkedListNode()
	{
		next = NULL;
	}
private:

};
class LinkedList
{
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void add(int value);
	void remove(int value);
	void printList();
	bool isCircular();
	void reverse(LinkedListNode* current , LinkedListNode* prev);
	LinkedListNode* getHead() { return head; }
	LinkedListNode* getTail() { return tail; }
	int getLength();
	//it deletes the entire list
	void clear();
private:
	LinkedListNode* head;
	LinkedListNode* tail;
	void clearUtility(LinkedListNode* current, LinkedListNode* prev);
};

