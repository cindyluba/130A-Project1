#include "hashTable.h"
#include "hashNode.h"

using namespace std; 

	hashTable::hashTable(int numberOfWords) {
		tableSize = (double(3)/2)*numberOfWords;
		table = new hashNode[tableSize];
	}
	hashTable::~hashTable() {

	}

	//returns a hashVal (key) 
	int hashTable::hashVal(string word, int tableSize) {
		int hashVal = 0;

	  	for(int i = 0; i<word.length();  i++) {
	    	hashVal = 37*hashVal+word[i];
	  	}
		hashVal %= tableSize;
	 	// if(hashVal<0) {
			// hashVal += tableSize;
	 	// }
		return hashVal;
	}

	// bool search(string word);  //search function
	// bool search(int key, string word);

	//insert function
	void hashTable::insert(string word) {
		int key = hashVal(word, tableSize);
		insert(key, word);
	}	
	void hashTable::insert(int key, string word) {
		hashNode* node = new hashNode(key, word);
		while(table[key].getIsOccupied() == true) {
			if(table[key].getWord() == word) {
				table[key].incrementCount();
				return;
			}
			if(key > tableSize) key = 0;
			key++;
		}
		table[key].setWord(word);
		table[key].incrementCount();
		table[key].setIsOccupied(true);
		table[key].setTombstone(false);

	}

	// void deleteWord(string word);	//delete function
	// void sort(); 				//sort function
	// void rangeSearch(string startWord, string endWord); //rangeSearch function




