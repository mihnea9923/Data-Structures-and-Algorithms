#pragma once

class Stack
{
private:
	int* stack;
	int size;
	int top = -1;
	
public:
	Stack(int size);
	void push(int value);
	int getTop();
	void pop();
	bool isEmpty();
};

