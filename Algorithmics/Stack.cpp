#include "Stack.h"
#include "Libs.h"
Stack::Stack(int size)
{
	this->size = size;
	stack = new int[size];
}

bool Stack::isEmpty()
{
	return top == -1;
}

void Stack::push(int value)
{
	if (top < size - 1)
	{
		top++;
		stack[top] = value;
	}
	else
	{
		cout << "Stack is full\n";
	}
}

int Stack::getTop()
{
	if (isEmpty())
	{
		cout << "Stack is empty\n";
		return INT_MAX;
	}
	else
	{
		return stack[top];
	}
}

void Stack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty\n";
	}
	else
	{
		top--;
	}
}