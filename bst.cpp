#include "bst.h"
#include <string>

using namespace std;

//constructor
BST::BST() {
	root = NULL;
}
//destructor
~BST(){
	destroyTree();
}

bool search(string word) {
	search(root, word);
}
bool search(Node* node, string word) {
	if(node == NULL) {
		return false;
	}
	if(node->word == word){	
		return true;
	} else if(node->word.compare(word) < 0) {
		search(node->leftChild, word);
	} else {
		search(node->rightChild, word);
	}
}

void insert(string word) {
		insert(root, word);
}
void insert(Node* node, string word) {
	//if root of BST is null, create a new node and set that to the root, otherwise, check comparision value and recursively call insert until there is an empty node
	if(node == NULL) {
		node = new Node(word);
	} else {
		if(node->word.compare(word) == 0) {
			node->wordCount += 1;
		} else if(node->word.compare(word) > 0){
			insert(node->rightChild, word);
		} else {
			insert(node->leftChild, word);
		}
	}
}
void delete(string word) {
	
}
void sort() {

}
void rangeSearch(string startWord, string endWord) {
	
}

void destroyTree() {
	destroyTree(root);
}

void destroyTree(Node* node) {
	if(leaf != NULL) {
		destroyTree(node->leftChild);
		destroyTree(node->rightChild);
		delete node;
	}
}



