#include "TrieNode.h"
#include<iostream>
#include<string>
using namespace std;

class Trie {

	TrieNode *root;

public:
	Trie () {
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode *root, string word) {
		if(word.size() == 0) {
			root->isTerminal = true;
			return;
		}	

		int index = word[0] - 'a';
		TrieNode *child;
		if(root->children[index] == NULL) {
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		else 
			child = root->children[index];
		insertWord(child, word.substr(1));
	}

	void insertWord(string word) {
		insertWord(root, word);
	}

	bool search( TrieNode *root, string word) {

		if(word.size() == 0 && root->isTerminal) {
			cout<<"found or not: "<<root->isTerminal<<" ";
			return root->isTerminal;
		}

		int index = word[0] - 'a';
		TrieNode *child = NULL;
		cout<<word<<" ";

		if(root->children[index] == NULL) 
			return false;
		else 
			child = root->children[index];

		search(child, word.substr(1));

		return false;
	}

	void search(string word) {
		cout<<search(root, word);
	}
};