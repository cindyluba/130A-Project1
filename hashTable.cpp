#include "hashTable.h"
#include "hashNode.h"
#include <iostream>

using namespace std; 

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
