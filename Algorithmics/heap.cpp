#include "heap.h"

heap::heap(int capacity)
{
	this->capacity = capacity;
	size = 0;
	heapContainer.resize(capacity);
}

void heap::insert(int value)
{
	if (size == capacity)
	{
		cout << "The heap is full\n";
		return;
	}
	size++;
	int i = size - 1;
	heapContainer[i] = value;
	
	while (i != 0 && heapContainer[parent(i)] > heapContainer[i])
	{
		swap(heapContainer[parent(i)], heapContainer[i]);
		i = parent(i);
	}
}

void heap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l < size && heapContainer[l] < heapContainer[i])
	{
		smallest = l;
	}
	if (r < size && heapContainer[r] < heapContainer[i])
	{
		smallest = r;
	}

	if (smallest != i)
	{
		swap(heapContainer[i], heapContainer[smallest]);
		heapify(smallest);
	}
}

int heap::extractMin()
{
	if (size == 0)
	{
		cout << "heap is empty\n";
		return -1;
	}
	if (size == 1)
	{
		return heapContainer[0];
		size--;
	}
	int root = heapContainer[0];
	heapContainer[0] = heapContainer[size - 1];
	size--;
	heapify(0);

	return root;
}