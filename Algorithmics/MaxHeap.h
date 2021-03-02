#pragma once
#include "Libs.h"
class MaxHeap
{
public:
	bool isEmpty() { return size == 0; }
	int top() { return v[1]; }
	void insert(int value);
	void shiftUp(int index);
	int extractMax();
	void shiftDown(int index);
private:
	int size = 0;
	vector<int> v = {0};
	int getParent(int node) { return node >> 1; } // nodde / 2
	int rightChild(int node) { return (node << 1) + 1;  } // node * 2 + 1
	int leftChild(int node) { return node << 1; } // node * 2
};

