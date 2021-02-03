#include "mergeSort.h"
#include <vector>
using namespace std;
void merge(vector<int> &v, int l, int mid, int r)
{
	vector<int> left, right;
	int it1 = 0, it2 = 0;
    int k = l;
	for (int i = l; i <= mid; i++)
	{
		left.push_back( v[i]);
	}
	for (int i = mid + 1; i <= r; i++)
	{
		right.push_back(v[i]);
	}
	while (it1 < left.size() && it2 < right.size())
	{
		if (left[it1] < right[it2])
		{
			v[k] = left[it1];
			it1++;
		}
		else
		{
			v[k] = right[it2];
			it2++;
		}
		k++;
	}
	while (it1 < left.size())
	{
		v[k] = left[it1];
		it1++;
		k++;
	}
	while (it2 < right.size())
	{
		v[k] = right[it2];
		it2++;
		k++;
	}
}



void mergeSort(vector<int>& v, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		mergeSort(v, l, mid);
		mergeSort(v, mid + 1, r);
		merge(v, l, mid, r);

	}
}

