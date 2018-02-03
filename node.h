#ifndef node_h
#define node_h

#include <string>

using namespace std;

class Node {

public:

	//constructor
	Node(string word);

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

#endif