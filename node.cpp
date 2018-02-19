#include "node.h"
#include <string>

//constructor
Node::Node(string newWord){
  leftChild = NULL;
  rightChild = NULL;
  word = newWord;
  wordCount = 1;
}

string Node::getWord() {
  return word;
}
int Node::getCount() {
  return wordCount;
}
void Node::incrementCount() {
  wordCount = wordCount++;
}
Node* Node::getLeft() {
  return leftChild;
}
Node* Node::getRight() {
  return rightChild;
}
