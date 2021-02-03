#pragma once
#include <iostream>
using namespace std;
class stack
{
private:
	int size = 100;
	int top ;
	int* arr;
public:
	stack()
	{
		arr = new int(size);
		top = -1;
	}
	bool isEmpty();
	bool isFull();
	void push(int value);
	void pop();
	void showTop();
	void printStack();
};

