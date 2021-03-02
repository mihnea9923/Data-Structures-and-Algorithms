#include "MaxHeap.h"
void MaxHeap::shiftUp(int index)
{
	if (index > size || index == 1)
		return;
	if (v[index] > v[getParent(index)])
	{
		swap(v[index], v[getParent(index)]);
		shiftUp(getParent(index));
	}
}

void MaxHeap::insert(int value)
{
	if (size + 1 >= v.size())
	{
		v.push_back(0);
	}
	v[++size] = value;
	shiftUp(size);
}

void MaxHeap::shiftDown(int index)
{
	if (index > size)
		return;
	int swapId = index;
	if (leftChild(index) <= size && v[leftChild(index)] > v[index])
		swapId = leftChild(index);
	if (rightChild(index) <= size && v[rightChild(index)] > v[swapId])
		swapId = rightChild(index);
	if (index != swapId)
	{
		swap(v[swapId], v[index]);
		shiftDown(swapId);
	}
}

int MaxHeap::extractMax()
{
	int maxNumber = v[1];
	swap(v[1], v[size--]);
	shiftDown(1);
	return maxNumber;
}