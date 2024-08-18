#pragma once
#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>
#include <string>
#include<set>

using namespace std;
class trieNode
{
public:

	char data;
	trieNode* children[26];
	bool isTerminal;

	//constructor
	trieNode(char ch)
	{
		this->data = ch;
		for (int i = 0; i < 26; i++)
		{
			this->children[i] = NULL;
		}
		isTerminal = false; //default to false
	}

private:

};

class Trie
{

public:

	trieNode* root;
	Trie()
	{
		root = new trieNode('\0');
	}
	void insertUtil(trieNode* root, string word) {
		if (word.length() == 0) {
			root->isTerminal = true;
			return;
		}
		int index = word[0] - 'a';
		trieNode* newChild;
		if (root->children[index] != NULL)
		{
			//child is present. take child end
			newChild = root->children[index];

		}
		else
		{
			//child absent
			//create new child node
			newChild = new trieNode(word[0]);
			//add newly created child to root terminal
			root->children[index] = newChild;
		}
		//recursion

		insertUtil(newChild, word.substr(1)); //return the substring from the starting index to the end of the string. end is empty here

	}

	void insert(string word) {
		return insertUtil(root, word);
	}

	bool searchUtil(trieNode* root, string word) {
		if (word.length() == 0)
		{
			if (root->isTerminal) {
				return true;
			}
			else
			{
				return false;
			}
		}

		int index = word[0] - 'a';
		trieNode* newChild;
		if (root->children[index] != NULL)
		{
			//child is present. search till end
			newChild = root->children[index];
		}
		else
		{
			//child absent
			//return false
			return false;
		}

		//recursion
		return searchUtil(newChild, word.substr(1)); //return the substring from the starting index to the end of the string. end is empty here
	}

	bool searchWord(string word) {
		return searchUtil(root, word);
	}

private:
};

