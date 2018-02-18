#ifndef node_h
#define node_h

#include <string>

using namespace std;

class hashNode {

public: 

	//constructor
	hashNode(int key, string word) {
		this.key = key;
		this.word = word;
	}
	~hashNode() {
	}

	string getWord() {
		return word;
	}

	int getCount() {
		return count;
	}


private:
	string word;
	int wordCount;


};


#endif