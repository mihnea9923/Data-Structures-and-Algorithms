#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <unordered_map>
#include "MaxHeap.h"
using namespace std;


int main()
{
	MaxHeap heap;
	heap.insert(4);
	heap.insert(3);
	heap.insert(20);
	heap.insert(25);
	heap.insert(7);
	heap.extractMax();
	heap.extractMax();
	cout << heap.top();
	
	return 0;
}

