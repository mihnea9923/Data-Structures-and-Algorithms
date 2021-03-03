#pragma once
#include "Libs.h"
class TrieNode {
public:
	TrieNode()
	{
		endWord = false;
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
	TrieNode* children[26];
	bool endWord;
};
class Trie
{
public:
	
	void insert(string s);
	bool search(string s);
private:
	TrieNode* root = new TrieNode();
};

