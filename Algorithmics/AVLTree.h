#pragma once
#include "Libs.h"
class Node {
public:
	int value;
	Node* left;
	Node* right;
	int height;
	Node(int value)
	{
		this->value = value;
		left = NULL;
		right = NULL;
	}
	Node(int value, int height)
	{
		this->value = value;
		this->height = height;
		left = NULL;
		right = NULL;
	}
};

class AVLTree
{
public:
	void add(int value);
	Node* getHead() { return head; }
private:
	Node* head = NULL;
	Node* addUtil(int value, Node* it);
	int nodeHeight(Node* node);	
	int balanceFactor(Node* node);
	Node* LLRotation(Node* node);
	Node* LRRotation(Node* node);
	Node* RRRotation(Node* node);
	Node* RLRotation(Node* node);

};

