#include "Searching.h"
int Searching::linearSearch(vector<int> v , int value)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i] == value)
			return i;
	return -1;
}

int Searching::binarySearch(vector<int> v, int value)
{
	int left = 0, right = v.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (v[mid] == value)
			return mid;
		if (v[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int Searching::jumpSearch(vector<int> v, int value)
{
	if (value < v[0] || value > v[v.size() - 1])
		return -1;
	int step = sqrt(v.size());
	int index = 0;
	while (v[min(v.size() - 1 , index)] < value)
	{
		index += step;
	}
	index = min(index, v.size() - 1);
	int prev = index - step + 1;
	for (int i = prev; i <= index; i++)
		if (v[i] == value)
			return i;

	return -1;
}