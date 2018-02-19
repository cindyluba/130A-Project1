#include "bst.h"
#include <iostream>
//#include "node.h"
#include <string>
#include <fstream>

using namespace std;

//constructor
BST::BST() {
  root = NULL;
}
//destructor
BST::~BST(){
  destroyTree();
}

bool BST::search(string word) {
  return search(root, word);
}
bool BST::search(Node* node, string word) {
  if(node == NULL) {
    return false;
  }
  if(word.compare(node->word) == 0){	
    return true;
  } else if(word.compare(node->word) < 0) {
    return search(node->left, word);
  } else {
    return search(node->right, word);
  }
  
}

Node* BST::getRoot() {
  return root;
}

void BST::insert(string word) {
  insert(root, word);
}
void BST::insert(Node*& node, string word) {
  //if root of BST is null, create a new node and set that to the root, otherwise, check comparision value and recursively call insert until there is an empty node
  if(node == NULL) {
    Node* newNode = new Node(word);
    node = newNode;
  } else {
    if(node->word.compare(word) == 0) {
      node->wordCount = node->wordCount + 1;
    } else if(word.compare(node->word) > 0){
      insert(node->right, word);
    } else {
      insert(node->left, word);
    }
  }
}

void BST::deleteWord(string word) {
  // Node* nodeToDelete = findNode(root, word);
  // if(nodeToDelete == NULL) {
  //   return;
  // } else {
  //   if(nodeToDelete->left==NULL && nodeToDelete->right==NULL) {
  //     delete nodeToDelete;
  //   } else if(nodeToDelete->right==NULL) {
  //     Node* leftTree = nodeToDelete->left;
  //     delete nodeToDelete->left;
  //     nodeToDelete = leftTree;
  //   } else if(nodeToDelete->left==NULL) {
  //     Node* rightTree = nodeToDelete->right;
  //     delete nodeToDelete->right;
  //     nodeToDelete = rightTree;
  //   } else {
  //     Node* currentNode = nodeToDelete->right;
  //     while (currentNode->left != NULL)
  // 	currentNode = currentNode->left;
  //     nodeToDelete->word = currentNode->word;
  //     delete currentNode;
  //   }

  // }

  deleteWord(root, word);
}

void BST::deleteWord(Node*& node, string word) {
  if (node == NULL)
    return;
  if (word.compare(node->word) < 0)
    deleteWord(node->left, word);
  else if (word.compare(node->word) > 0)
    deleteWord(node->right, word);
  else {
    if (node->wordCount > 1) {
      node->wordCount = node->wordCount - 1;
    }
    else {
      if (node->left == NULL) {
	Node* temp = node;
	node = node->right;
	delete temp;
      }
      else if (node->right == NULL) {
	Node* temp = node;
	node = node->left;
	delete temp;
      }
      else {
	Node* temp = node;
	while (temp->right != NULL)
	  temp = temp->right;
	node->word = temp->word;
	delete temp;
      }
    }
  }
}

Node* BST::findNode(Node* node, string word) {
  if(node == NULL) {
    return NULL;
  }
  if(node->word == word){	
    return node;
  } else if(node->word.compare(word) < 0) {
    search(node->left, word);
  } else {
    search(node->right, word);
  }
  return NULL;
}

void BST::sort() {
  ofstream outFile;
  outFile.open("sorted_output.txt");
  sort(root, outFile);
}

void BST::sort(Node* node, ofstream& outFile) {
  sort(node->left, outFile);
  outFile << node->word;
  sort(node->right, outFile);
}

void BST::rangeSearch(string startWord, string endWord) {
  rangeSearch(root, startWord, endWord);
}

void BST::rangeSearch(Node* node, string startWord, string endWord) {
  if (node == NULL)
    return;
  if (startWord < node->word)
    rangeSearch(node->left, startWord, endWord);
  if (startWord <= node->word && endWord >= node->word)
    cout << node->word << endl;
  if (endWord > node->word)
    rangeSearch(node->right, startWord, endWord);
}

void BST::destroyTree() {
  destroyTree(root);
}

int BST::countWords() {
  return countWords(root);
}

int BST::countWords(Node* node) {
  int count = 0;
  if (node == NULL)
    return 0;
  count += countWords(node->left);
  count += 1;
  count += countWords(node->right);
  return count;
}

void BST::printInorder() {

  printInorder(root);
  
}

void BST::printInorder(Node* node) {

  if (node == NULL)
    return;

  printInorder(node->left);
  cout << node->word << ": " << node->wordCount << " " << endl;
  printInorder(node->right);

}

void BST::destroyTree(Node* node) {
  if(node != NULL) {
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}
