#ifndef node_h
#define node_h

class Node {

public:

	//constructor
	Node(String word);

	string getWord();
	int getCount();
	Node* getLeft();
	Node* getRight();

private:
	Node* leftChild;
	Node* rightChild;
	string word;
	int wordCount;

};