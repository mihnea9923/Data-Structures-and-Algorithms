#include "stack.h"

bool stack::isEmpty()
{
	return top == -1;
}

bool stack::isFull()
{
	return top == size - 1; 
}
void stack::push(int value)
{
	if(isFull())
	{
		cout << "The stack is full \n";
		return;
	}
	top++;
	arr[top] = value;
}

void stack::pop()	
{
	if (isEmpty())
	{
		cout << "The stack is empty\n";
		return;
	}
	top--;
}

void stack::showTop()
{
	if (isEmpty())
	{
		cout << "The stack is empty\n";
		return;
	}
	cout << "The top value is: " << arr[top] << endl;
}

void stack::printStack()
{
	for (int i = 0; i <= top; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}