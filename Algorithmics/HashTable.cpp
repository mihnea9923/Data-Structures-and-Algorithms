#include "HashTable.h"
int HashTable::hashFunction(int key)
{
	return key % size;
}

void HashTable::add(int key, int value)
{
	int hash = hashFunction(key);
	for (auto it = table[hash].begin(); it != table[hash].end(); it++)
	{
		if (it->first == key)
		{
			cout << "Key already exists" << endl;
			return;
		}
	}
	table[hash].push_back({ key , value });
}

bool HashTable::isEmpty()
{
	int sum{};
	for (auto x : table)
	{
		for (auto it : x)
			sum += it.first;
	}
	return sum == 0;
}

int HashTable::search(int key)
{
	int hash = hashFunction(key);
	for (auto it = table[hash].begin(); it != table[hash].end(); it++)
	{
		if (it->first == key)
			return it->second;
	}
	cout << "Key does not exist\n";
	return -1;
}

void HashTable::removeItem(int key)
{
	int hash = hashFunction(key);
	for (auto it = table[hash].begin(); it != table[hash].end(); it++)
	{
		if (it->first == key)
		{
			table[hash].erase(it);
			return;
		}
	}
	cout << "Item can not be deleted because key does not exist\n";
}