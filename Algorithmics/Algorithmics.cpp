#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <unordered_map>
#include "Sorting.h"
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int main()
{
	TreeNode* root = new TreeNode(3);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(4);
	root->right->left = new TreeNode(1);
	Sorting s;
	vector<int> v = { 1 , 4 , 3 , 2 , 6 , 1 , 6 , 3};
	s.quickSort(v , 0 , v.size() - 1);
	for (auto x : v)
		cout << x << endl;
	return 0;
}

