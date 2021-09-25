#include "TrieNode.h"
#include<iostream>
#include<string>
#include<bits/stdc++.h>
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
			cout<<"Setting of isTerminal: "<<root->isTerminal<<" at "<<word<<endl;
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
		if(word.size() == 1 && root->isTerminal) return true;
		int index = word[0] - 'a';
		if(root->children[index] == NULL) return 0;
		int i=0;
		if(root->children[index]->data == word[i])
		{
			// if(word.size() == 0 && root->isTerminal == true) {
			// 	cout<<word[index];
			// 	return true;
			// }
			cout<<root->children[index]->data<<" "<<word.size()<<" "<<word<<" "<<root->isTerminal<<endl;
			TrieNode *child = root->children[index];
			i++;
			search(child, word.substr(1));
		}
		// if(word.size() == 0 && root->isTerminal) {
		// 	return true;
		// }
		// TrieNode *child;
		// int index = word[0] - 'a';

		// if(root->children[index] == NULL) 
		// {
		// 	if(root->isTerminal) return 5356;
		// 	else return 25786;	
		// }
		// else
		// 	child = root->children[index];
		// search(child, word.substr(1));
		// return 0;
		return 0;
	}

	void search(string word) {
		cout<<search(root, word);
	}
	
	void remove (string word) {
		
	}
};
