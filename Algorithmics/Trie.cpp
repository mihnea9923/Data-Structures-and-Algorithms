#include "Trie.h"
void Trie::insert(string s)
{
	if (s.size() == 0)
		return;
	TrieNode* it = root;
	for (int i = 0; i < s.size(); i++)
	{
		int currentLeter = s[i] - 'a';
		if (it->children[currentLeter] == NULL)
		{
			it->children[currentLeter] = new TrieNode();
		}
		it = it->children[currentLeter];
	}
	it->endWord = true;
}

bool Trie::search(string s)
{
	if (s.size() == 0)
		return true;
	TrieNode* it = root;
	for (int i = 0; i < s.size(); i++)
	{
		char currentLetter = s[i] - 'a';
		if (it->children[currentLetter] == NULL)
			return false;
		it = it->children[currentLetter];
	}
	return it != NULL && it->endWord;
}