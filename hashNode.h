#ifndef node_h
#define node_h

#include <string>

using namespace std;

class hashNode {

public: 

	//constructor
	hashNode(){
		isOccupied = false;
		tombstone = false;
	}

	hashNode(int key, string word) {
		this->key = key;
		this->word = word;
	}

	string getWord() {
		return word;
	}
	void setWord(string word) {
		this->word = word;
	}
	int getCount() {
		return wordCount;
	}
	void incrementCount() {
		wordCount++;
	}
	bool getIsOccupied() {
		return isOccupied;
	}
	bool getTombstone() {
		return tombstone;
	}
	void setIsOccupied(bool val) {
		isOccupied = val;
	}
	void setTombstone(bool val) {
		tombstone = val;
	}

private:
	string word;
	int key;
	int wordCount;
	bool isOccupied;
	bool tombstone;

};


#endif