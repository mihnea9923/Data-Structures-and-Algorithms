#pragma once
#include <iostream>
using namespace std;
class Queue
{
private:
	int* queue;
	int size;
	int front = -1;
	int rear = -1;
public:
	Queue(int size)
	{
		this->size = size;
		queue = new int(size);
	}
	bool isEmpty();
	void enqueue(int value);
	void dequeue();
	int showFront();
	void displayQueue();
};



