#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	BinarySearchTree tree;
	tree.add(5);
	tree.add(4);
	tree.add(3);
	tree.add(3);
	tree.add(2);
	tree.add(1);
	tree.add(7);
	tree.add(6);
	tree.add(8);
	tree.remove(7);
	tree.inorder();
	return 0;
}

