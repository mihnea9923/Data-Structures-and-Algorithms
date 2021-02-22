#include "AVLTree.h"
void AVLTree::add(int value)
{
	Node* it = head;
	head = addUtil(value, it);
}

Node* AVLTree::addUtil(int value, Node* it)
{
	if (it == NULL)
	{
		return new Node(value , 1);
	}
	if (it->value < value)
	{
		it->right = addUtil(value, it->right);
	}
	else
	{
		it->left = addUtil(value, it->left);
	}
	it->height = nodeHeight(it);
	
	if (balanceFactor(it) == 2)
	{
		if (balanceFactor(it->left) == 1)
			return LLRotation(it);
		else
			return LRRotation(it);
	}
	else if(balanceFactor(it) == -2)
	{
		if (balanceFactor(it->right) == -1)
			return RRRotation(it);
		else
			return RLRotation(it);
	}
	
	return it;
}

int AVLTree::nodeHeight(Node* node)
{
	int leftHeight = 0, rightHeight = 0;
	if (node->left)
		leftHeight = node->left->height;
	if (node->right)
		rightHeight = node->right->height;
	return max(leftHeight, rightHeight) + 1;
}

int AVLTree::balanceFactor(Node* node)
{
	int leftHeight = 0, rightHeight = 0;
	if (node->left)
		leftHeight = node->left->height;
	if (node->right)
		rightHeight = node->right->height;
	return leftHeight - rightHeight;
}

Node* AVLTree::LLRotation(Node* node)
{
	Node* left = node->left;
	Node* leftRight = left->right;

	left->right = node;
	node->left = leftRight;
	node->height = nodeHeight(node);
	left->height = nodeHeight(left);
	
	if (head == node)
		head = left;
	return left;
}

Node* AVLTree::LRRotation(Node* node)
{
	Node* left = node->left;
	Node* leftRight = left->right;

	left->right = leftRight->left;
	node->left = leftRight->right;
	leftRight->left = left;
	leftRight->right = node;
	
	left->height = nodeHeight(left);
	leftRight->height = nodeHeight(leftRight);
	node->height = nodeHeight(node);
	if (head == node)
		head = leftRight;
	return leftRight;
}

Node* AVLTree::RLRotation(Node* node)
{
	Node* right = node->right;
	Node* rightLeft = right->left;
	node->right = rightLeft->left;
	right->left = rightLeft->right;
	rightLeft->left = node;
	rightLeft->right = right;

	right->height = nodeHeight(right);
	rightLeft->height = nodeHeight(rightLeft);
	node->height = nodeHeight(node);

	if (node == head)
		head = rightLeft;
	return rightLeft;
}
Node* AVLTree::RRRotation(Node* node)
{
	Node* right = node->right;
	Node* rightLeft = right->left;
	right->left = node;
	node->right = rightLeft;

	node->height = nodeHeight(node);
	right->height = nodeHeight(right);

	if (head == node)
		head = right;
	return right;
}