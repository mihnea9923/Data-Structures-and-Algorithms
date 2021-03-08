#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <unordered_map>
#include "Trie.h"
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    
	return 0;
}

