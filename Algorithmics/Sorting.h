#pragma once
#include "Libs.h"
#include <vector>
class Sorting
{
public:
	void mergeSort(vector<int>& v , int left , int right);
	void quickSort(vector<int>& v , int left , int right);
	void selectionSort(vector<int>& v);
private:
	void merge(vector<int>& v, int left, int right);
	int partition(vector<int>& v, int left, int right);
};

