#include "bst.h"
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
    search(node->leftChild, word);
  } else {
    search(node->rightChild, word);
  }
}

void BST::insert(string word) {
  insert(root, word);
}
void BST::insert(Node* node, string word) {
  //if root of BST is null, create a new node and set that to the root, otherwise, check comparison value and recursively call insert until there is an empty node
  if(node == NULL) {
    node = new Node(word);
  } else {
    if(node->word.compare(word) == 0) {
      node->wordCount += 1;
    } else if(node->word.compare(word) > 0){
      insert(node->rightChild, word);
    } else {
      insert(node->leftChild, word);
    }
  }
}
void BST::deleteWord(string word) {
  Node* nodeToDelete = findNode(root, word);
  if(nodeToDelete == NULL) {
    return;
  } else {
    if(nodeToDelete->leftChild==NULL && nodeToDelete->rightChild==NULL) {
      delete nodeToDelete;
    } else if(nodeToDelete->rightChild==NULL) {
      Node* leftTree = nodeToDelete->leftChild;
      delete nodeToDelete->leftChild;
      nodeToDelete = leftTree;
    } else if(nodeToDelete->leftChild==NULL) {
      Node* rightTree = nodeToDelete->rightChild;
      delete nodeToDelete->rightChild;
      nodeToDelete = rightTree;
    } else {
      Node* currentNode = nodeToDelete->rightChild;
      while (currentNode->leftChild != NULL)
	currentNode = currentNode->leftChild;
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
    search(node->leftChild, word);
  } else {
    search(node->rightChild, word);
  }
}
void BST::sort() {

}

void BST::rangeSearch(string startWord, string endWord) {
	
}

void BST::destroyTree() {
  destroyTree(root);
}

void BST::destroyTree(Node* node) {
  if(leaf != NULL) {
    destroyTree(node->leftChild);
    destroyTree(node->rightChild);
    delete node;
  }
}



