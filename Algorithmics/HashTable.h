#pragma once
#include "Libs.h"
#include <list>
class HashTable
{
public:
	void add(int key, int value);
	bool isEmpty();
	int hashFunction(int key);
	void removeItem(int key);
	int search(int key);
private:
	static const int size = 10;
	list<pair<int , int>> table[size];
};

