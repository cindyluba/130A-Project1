#ifndef bst_h
#define bst_h

#include <string>
//#include "node.h"

using namespace std;

struct Node {
  Node *left, *right;
  string word;
  int wordCount;

  Node(string word) {
    left = NULL;
    right = NULL;
    this->word = word;
    wordCount = 1;
  }
};

class BST {

 public:

  //constructor
  BST();
  ~BST();

  bool search(string word);  //search function
  //  bool search(Node* node, string word);
  void insert(string word);	//insert function
  //  void insert(Node* node, string word);
  Node* getRoot();
  void deleteWord(string word);	//delete function
  Node* findNode(Node* node, string word);
  void sort(); 				//sort function
  void rangeSearch(string startWord, string endWord); //rangeSearch function 
  void printInorder();
  void destroyTree();


 private:
  Node* root;
  bool search(Node* node, string word);
  void insert(Node*& node, string word);
  void printInorder(Node* node);
  void destroyTree(Node* node);

};

#endif
