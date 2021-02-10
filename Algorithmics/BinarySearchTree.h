#pragma once
#include "Libs.h"
class Node {
public:
	int value;
	Node* left = NULL;
	Node* right = NULL;
	Node(int value) { this->value = value; }
	Node(){}
private:
};

class BinarySearchTree
{
public:
	Node* getHead() { return head; }
	void add(int value);
	void remove(int value);
	void preorder();
	void inorder();
	void postorder();
private:
	Node* head = NULL;
	void preorderUtil(Node* it);
	void postorderUtil(Node* it);
	void inorderUtil(Node* it);
	void addUtil(Node* it, Node* node);
	void removeUtil(Node* it, int value);
};

