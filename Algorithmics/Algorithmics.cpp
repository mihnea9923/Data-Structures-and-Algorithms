#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <unordered_map>
#include "AVLTree.h"
using namespace std;


int main()
{
	AVLTree tree;
	tree.add(10);
	tree.add(5);
	tree.add(3);
	cout << tree.getHead()->value;
	return 0;
}

