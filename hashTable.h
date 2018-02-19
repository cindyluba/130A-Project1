#ifndef hash_h
#define hash_h

#include <string>
#include "hashNode.h"

using namespace std;

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