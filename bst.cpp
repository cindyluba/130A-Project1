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
	if(node->getWord() == word){	
		return true;
	} else if(node->getWord().compare(word) < 0) {
		search(node->getLeft(), word);
	} else {
		search(node->getRight(), word);
	}
}

void BST::insert(string word) {
		insert(root, word);
}
void BST::insert(Node* node, string word) {
	//if root of BST is null, create a new node and set that to the root, otherwise, check comparision value and recursively call insert until there is an empty node
	if(node == NULL) {
		node = new Node(word);
	} else {
		if(node->getWord().compare(word) == 0) {
			node->incrementCount();
		} else if(node->getWord().compare(word) > 0){
			insert(node->getRight(), word);
		} else {
			insert(node->getLeft(), word);
		}
	}
}

void BST::deleteWord(string word) {
  Node* nodeToDelete = findNode(root, word);
  if(nodeToDelete == NULL) {
    return;
  } else {
    if(nodeToDelete->getLeft()==NULL && nodeToDelete->getRight()==NULL) {
      delete nodeToDelete;
    } else if(nodeToDelete->getRight()==NULL) {
      Node* leftTree = nodeToDelete->getLeft();
      delete nodeToDelete->getLeft();
      nodeToDelete = leftTree;
    } else if(nodeToDelete->getLeft()==NULL) {
      Node* rightTree = nodeToDelete->getRight();
      delete nodeToDelete->getRight();
      nodeToDelete = rightTree;
    } else {
      Node* currentNode = nodeToDelete->getRight();
      while (currentNode->getLeft() != NULL)
	currentNode = currentNode->getLeft();
      nodeToDelete->getWord() = currentNode->getWord();
      delete currentNode;
    }

  }
}
Node* BST::findNode(Node* node, string word) {
  if(node == NULL) {
    return NULL;
  }
  if(node->getWord() == word){	
    return node;
  } else if(node->getWord().compare(word) < 0) {
    search(node->getLeft(), word);
  } else {
    search(node->getRight(), word);
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
	if(node != NULL) {
		destroyTree(node->getLeft());
		destroyTree(node->getRight());
		delete node;
	}
}



