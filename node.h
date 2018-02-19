#ifndef node_h
#define node_h

#include <string>

using namespace std;

class Node {

public:

	//constructor
	Node(string word);
	~Node();

	string getWord();
	int getCount();
	void incrementCount();
	Node* getLeft();
	Node* getRight();

private:
	Node* leftChild;
	Node* rightChild;
	string word;
	int wordCount;

};

#endif