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

		if(word.size() == 0) {
			return root->isTerminal;
		}

		int index = word[0] - 'a';
		TrieNode *child;
		if(root->children[index])
			child = root->children[index];
		else 
			return false;

		return search(child, word.substr(1));
	}

	bool search(string word) {
		return search(root, word);
	}

	void remove(TrieNode *root, string word) {
		if(word.size()==0) {
			root->isTerminal = false;
			return;
		}

		TrieNode *child;
		int index = word[0] - 'a';
		if(root->children[index]) {
			child = root->children[index];
		}
		else 
			return;

		remove(child, word.substr(1));

		if(child -> isTerminal == false) {
			for(int i=0; i<26; i++) {
				if(word[i]) return;
			}
			delete child;
			root->children[index] = NULL;
		}

	}

	void remove (string word) {
		remove(root, word);
	}
};
