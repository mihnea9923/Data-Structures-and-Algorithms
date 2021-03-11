#include "Sorting.h"
void Sorting::selectionSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1 ; j < v.size(); j++)
		{
			if (v[j] < v[minIndex])
				minIndex = j;
		}
		swap(v[i], v[minIndex]);
	}
}

void Sorting::mergeSort(vector<int>& v, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(v, left, mid);
		mergeSort(v, mid + 1, right);
		merge(v, left, right);
	}
}

void Sorting::merge(vector<int>& v, int left, int right)
{
	int mid = left + (right - left) / 2;
	vector<int> l, r , m;
	for (int i = left; i <= mid; i++)
		l.push_back(v[i]);
	for (int i = mid + 1; i <= right; i++)
		r.push_back(v[i]);
	int i = 0, j = 0;
	while (i < l.size() && j < r.size())
	{
		if (l[i] < r[j])
		{
			m.push_back(l[i]);
			i++;
		}
		else
		{
			m.push_back(r[j]);
			j++;
		}
	}
	while (i < l.size())
		m.push_back(l[i++]);
	while (j < r.size())
		m.push_back(r[j++]);
	for (int i = left; i <= right; i++)
		v[i] = m[i - left];
}

void Sorting::quickSort(vector<int>& v, int left, int right)
{
	if (left < right)
	{
		int pivot = partition(v, left, right);
		quickSort(v,left , pivot - 1);
		quickSort(v, pivot + 1 , right);
	}
}

int Sorting::partition(vector<int>& v, int left, int right)
{
	int index = left;
	for (int i = left; i < right; i++)
	{
		if (v[i] < v[right])
		{
			swap(v[i], v[index]);
			index++;
		}
	}
	swap(v[index], v[right]);
	return index;
}