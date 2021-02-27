#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <unordered_map>
#include "LinkedList.h"
using namespace std;


int main()
{
	
	LinkedList l;
	l.add(1);
	l.add(2);
	l.add(3);
	l.add(4);
	l.add(5);
	l.clear();
	cout << l.getLength();
	return 0;
}

