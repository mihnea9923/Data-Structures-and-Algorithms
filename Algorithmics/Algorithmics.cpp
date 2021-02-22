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
	tree.add(14);
	tree.add(12);
	tree.add(11);
	tree.add(13);
	cout << tree.getHead()->left->right->value;
	return 0;
}

