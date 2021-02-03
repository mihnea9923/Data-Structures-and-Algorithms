#include "Queue.h"

bool Queue::isEmpty()
{
	return front == -1 && rear == -1;
}

void Queue::enqueue(int value)
{
	if (front == -1)
	{
		front = 0;
	}
	if (rear < size)
	{
		rear++;
		queue[rear] = value;
	}
	else
	{
		//I could create a larger array,but it's beyond the purpose of this implementation
		cout << "Queue is full\n";
	}
}

void Queue::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is empty\n";
		return;
	}

	if (front == rear)
	{
		front = -1;
		rear = -1;
		return;
	}
	else
	{
		front++;
	}
}

int Queue::getFront()
{
	if (!isEmpty())
	{
		return queue[front];
	}
	cout << "Queue is empty";
	return INT_MAX;
}
