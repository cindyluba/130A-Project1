#include "hashTable.h"
#include "hashNode.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

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
  while(table[key].getIsOccupied()) {
    if(word.compare(table[key].getWord()) == 0) {
      table[key].incrementCount();
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
}

void HashTable::deleteWord(string word) { //delete function
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
void HashTable::sort() { //sort function
  vector<string> wordList;
  for(int i = 0; i < tableSize; i++) {
    if(table[i].getIsOccupied()) {
      wordList.push_back(table[i].getWord());
    }
  }
  std::sort(wordList.begin(), wordList.end());
  ofstream outFile;
  outFile.open("output.txt", ios_base::app);
  for(string s : wordList) {
    outFile << s << endl;
  }
  outFile.close();
}

void HashTable::rangeSearch(string startWord, string endWord) { //rangeSearch function
  for(int i = 0; i < tableSize; i++) {
    if(table[i].getIsOccupied() && table[i].getWord() >= startWord && table[i].getWord() <= endWord) {
      cout << table[i].getWord() << endl;
    }
  }
}
