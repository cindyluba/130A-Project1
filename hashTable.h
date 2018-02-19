#ifndef hash_h
#define hash_h

#include <string>
#include "hashNode.h"

using namespace std;

<<<<<<< HEAD
class hashTable {

public:

	hashTable(int numberOfWords);
	~hashTable();

	//returns a hashVal (key) 
	int hashVal(string word, int tableSize);
	bool search(string word);  //search function
	bool search(int key, string word);
	void insert(string word);	//insert function
	void insert(int key, string word);
	void deleteWord(string word);	//delete function
	void sort(); 				//sort function
	void rangeSearch(string startWord, string endWord); //rangeSearch function



private:
	int tableSize;
	hashNode *table;
};

#endif
=======
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
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
