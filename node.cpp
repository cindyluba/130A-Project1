#include "node.h"

class Node {

public:

	//constructor
	Node::Node(String word){
		leftChild = NULL;
		rightChild = NULL;
		this.word = word;
		wordCount = 1;
	}

	string Node::getWord() {
		return this.word;
	}
	int Node::getCount() {
		return this.wordCount;
	}
	Node* Node::getLeft() {
		return this->leftChild;
	}
	Node* Node::getRight() {
		return this->rightChild;
	}
	
private:
	Node* leftChild;
	Node* rightChild;
	string word;
	int wordCount;

};