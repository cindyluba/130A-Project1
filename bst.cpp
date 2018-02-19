#include "bst.h"
#include <iostream>
//#include "node.h"
#include <string>

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
  search(root, word);
}
bool BST::search(Node* node, string word) {
  if(node == NULL) {
    return false;
  }
  if(node->word == word){	
    return true;
  } else if(node->word.compare(word) < 0) {
    search(node->left, word);
  } else {
    search(node->right, word);
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
  Node* nodeToDelete = findNode(root, word);
  if(nodeToDelete == NULL) {
    return;
  } else {
    if(nodeToDelete->left==NULL && nodeToDelete->right==NULL) {
      delete nodeToDelete;
    } else if(nodeToDelete->right==NULL) {
      Node* leftTree = nodeToDelete->left;
      delete nodeToDelete->left;
      nodeToDelete = leftTree;
    } else if(nodeToDelete->left==NULL) {
      Node* rightTree = nodeToDelete->right;
      delete nodeToDelete->right;
      nodeToDelete = rightTree;
    } else {
      Node* currentNode = nodeToDelete->right;
      while (currentNode->left != NULL)
	currentNode = currentNode->left;
      nodeToDelete->word = currentNode->word;
      delete currentNode;
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
}



void BST::sort() {

}
void BST::rangeSearch(string startWord, string endWord) {
	
}

void BST::destroyTree() {
  destroyTree(root);
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
