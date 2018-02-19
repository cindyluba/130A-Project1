#ifndef bst_h
#define bst_h

#include <string>
#include <fstream>
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
<<<<<<< HEAD

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
=======
  void printInorder();
  bool search(string word);  //search function
  void insert(string word);	//insert function
  Node* getRoot();
  void deleteWord(string word);	//delete function
  void sort(); 				//sort function
  void rangeSearch(string startWord, string endWord); //rangeSearch function 
  int countWords();
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
  void destroyTree();


 private:
  Node* root;
<<<<<<< HEAD
  bool search(Node* node, string word);
  void insert(Node*& node, string word);
  void printInorder(Node* node);
=======
  void printInorder(Node* node);
  bool search(Node* node, string word);
  void insert(Node*& node, string word);
  void deleteWord(Node*& node, string word);
  void sort(Node* node, ofstream& outFile);
  void rangeSearch(Node* node, string startWord, string endWord);
  int countWords(Node* node);
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
  void destroyTree(Node* node);

};

#endif
