#include "hashTable.h"
#include "hashNode.h"
<<<<<<< HEAD
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
=======
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
#include <iostream>

using namespace std; 

<<<<<<< HEAD
	hashTable::hashTable(int numberOfWords) {
		tableSize = (double(3)/2)*numberOfWords;
		table = new hashNode[tableSize];
	}
	hashTable::~hashTable() {
		delete [] table;
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

	//search function
	bool hashTable::search(string word){
		int key = hashVal(word, tableSize);
		search(key, word);
	}  
	bool hashTable::search(int key, string word){
		while(table[key].getWord() != word) {
			if(!table[key].getIsOccupied() && !table[key].getTombstone()) {
				return false;
			}
			key++;
			if(key > tableSize) key = 0;
		}
		return true;
	}

	//insert function
	void hashTable::insert(string word) {
		int key = hashVal(word, tableSize);
		insert(key, word);
	}	
	void hashTable::insert(int key, string word) {
		while(table[key].getIsOccupied() == true) {
			if(table[key].getWord() == word) {
				table[key].incrementCount();
				return;
			}
			key++;
			if(key > tableSize) key = 0;
		}
		table[key].setWord(word);
		table[key].incrementCount();
		table[key].setIsOccupied(true);
		table[key].setTombstone(false);

	}

	void hashTable::deleteWord(string word) {
		int key = hashVal(word, tableSize);
		while(table[key].getWord() != word) {
			if(!table[key].getIsOccupied() && !table[key].getTombstone()) {
				return;
			}
			key++;
		}
		table[key].decrementCount();
		if(table[key].getCount() == 0) {
			table[key].setWord("");
			table[key].setTombstone(true);
			table[key].setIsOccupied(false);
		}
	}
	void hashTable::sort() {
		vector<string> names;
		for(int i = 0; i < tableSize; i++) {
			if(table[i].getIsOccupied()) {
				names.push_back(table[i].getWord());
			}
		}
		sort(names.begin(), names.end());
		ofstream outFile;
		outFile.open("hash_sorted_output.txt");
		for(string s: names) {
			outFile << s << endl;
		}
		outFile.close();
	}
	void hashTable::rangeSearch(string startWord, string endWord) {
		for(int i = 0; i < tableSize; i++) {
			if(table[i].getIsOccupied() && table[i].getWord() >= startWord && table[i].getWord() <= endWord) {
				cout << table[i].getWord() << endl;
			}
		}
	}




=======
HashTable::HashTable(int numberOfWords) {
  tableSize = (double(3)/2)*numberOfWords;
  table = new hashNode[tableSize];
}
HashTable::~HashTable() {
  delete [] table;
}

//returns a hashVal (key) 
int HashTable::hashVal(string word, int tableSize) {
  unsigned int hashVal = 0;
  cout << word << endl;
  for(unsigned int i = 0; i<word.length();  i++) {
    hashVal = 37*hashVal+(unsigned char)word[i];
  }
  hashVal %= tableSize;
  return hashVal;
} 

bool HashTable::search(string word) { //search function
  int key = hashVal(word, tableSize);
  while(table[key].getWord() != word) {
    if(!table[key].getIsOccupied() && !table[key].getTombstone()) {
      return false;
    }
    key++;
    if (key > tableSize)
      key = 0;
  }
  return true;
}

//insert function
void HashTable::insert(string word) {
  int key = hashVal(word, tableSize);
  cout << key << endl;
  while(table[key].getIsOccupied()) {
    if(word.compare(table[key].getWord()) == 0) {
      table[key].incrementCount();
      cout << "uhhhh" << endl;
      return;
    }
    key++;
    if (key > tableSize-1)
      key = 0;
  }
  table[key].setWord(word);
  table[key].incrementCount();
  table[key].setIsOccupied(true);
  table[key].setTombstone(false);
  cout << "fuckkkkkk" << endl;
}

// void deleteWord(string word);	//delete function
// void sort(); 				//sort function
// void rangeSearch(string startWord, string endWord); //rangeSearch function
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
