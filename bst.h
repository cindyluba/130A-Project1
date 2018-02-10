#ifndef bst_h
#define bst_h

#include <string>
#include "node.h"

using namespace std;

class BST {

public:

	//constructor
	BST();
	~BST();

	bool search(string word);  //search function
	bool search(Node* node, string word);
	void insert(string word);	//insert function
	void insert(Node* node, string word);
	void delete(string word);	//delete function
	void sort(); 				//sort function
	void rangeSearch(string startWord, string endWord); //rangeSearch function 
	void destroyTree();


private:
	Node* root;
	void destroyTree(Node* node);

};

#endif