#ifndef hash_h
#define hash_h

#include <string>
#include "hashNode.h"

using namespace std;

class HashTable {

 public:

  HashTable(int numberOfWords);
  ~HashTable();

  //returns a hashVal (key) 
  int hashVal(string word, int tableSize);
  bool search(string word);  //search function
  void insert(string word);	//insert function
  void deleteWord(string word);	//delete function
  void sort(); 				//sort function
  void rangeSearch(string startWord, string endWord); //rangeSearch function



 private:
  int tableSize;
  hashNode *table;
  bool search(int key, string word);
};

#endif
