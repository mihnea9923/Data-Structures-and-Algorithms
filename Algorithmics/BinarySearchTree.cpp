#include "BinarySearchTree.h"
void BinarySearchTree::add(int value)
{
	Node* newNode = new Node(value);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	Node* it = head;
	addUtil(it, newNode);
}

void BinarySearchTree::preorder()
{
	Node* it = head;
	preorderUtil(it);
}

void BinarySearchTree::inorder()
{
	Node* it = head;
	inorderUtil(it);
}

void BinarySearchTree::postorder()
{
	Node* it = head;
	postorderUtil(it);
}

void BinarySearchTree::preorderUtil(Node*it)
{
	if (it)
	{
		cout << it->value << " ";
		preorderUtil(it->left);
		preorderUtil(it->right);
	}
}

void BinarySearchTree::inorderUtil(Node* it)
{
	if (it)
	{
		inorderUtil(it->left);
		cout << it->value << " ";
		inorderUtil(it->right);
	}
}

void BinarySearchTree::postorderUtil(Node* it)
{
	if(it)
	{
		postorderUtil(it->left);
		postorderUtil(it->right);
		cout << it->value << " ";
	}
}

void BinarySearchTree::addUtil(Node* it , Node* node)
{
	if (it->value < node->value)
	{
		if (it->right == NULL)
		{
			it->right = node;
			return;
		}
		else addUtil(it->right, node);
	}
	else if (it->value > node->value)
	{
		if (it->left == NULL)
		{
			it->left = node;
			return;
		}
		else addUtil(it->left, node);
	}
}

void BinarySearchTree::remove(int value)
{
	if (head == NULL)
		return;
	if (head->value == value)
	{
		head = NULL;
		return;
	}
	Node* it = head;
	removeUtil(it, value);
}

void BinarySearchTree::removeUtil(Node* it, int value)
{

}
