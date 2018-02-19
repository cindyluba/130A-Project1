#ifndef node_h
#define node_h

#include <string>

using namespace std;

class hashNode {

<<<<<<< HEAD
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
	void decrementCount() {
		wordCount--;
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
=======
 public: 

  //constructor
  hashNode(){
    isOccupied = false;
    tombstone = false;
  }

  hashNode(int key, string word) {
    this->key = key;
    this->word = word;
    wordCount = 1;
    isOccupied = true;
    tombstone = false;
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
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e

};


<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
