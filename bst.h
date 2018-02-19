#ifndef bst_h
#define bst_h

#include <string>
#include <fstream>

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
  void printInorder();
  bool search(string word);  //search function
  void insert(string word);	//insert function
  Node* getRoot();
  void deleteWord(string word);	//delete function
  void sort(); 				//sort function
  void rangeSearch(string startWord, string endWord); //rangeSearch function 
  int countWords();
  void destroyTree();


 private:
  Node* root;
  void printInorder(Node* node);
  bool search(Node* node, string word);
  void insert(Node*& node, string word);
  void deleteWord(Node*& node, string word);
  void sort(Node* node, ofstream& outFile);
  void rangeSearch(Node* node, string startWord, string endWord);
  int countWords(Node* node);
  void destroyTree(Node* node);

};

#endif
