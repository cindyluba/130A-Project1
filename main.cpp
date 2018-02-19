#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <experimental/filesystem>
#include <fstream>
#include <boost/timer.hpp>
#include "bst.h"
#include "hashTable.h"

using namespace std;

namespace fs = experimental::filesystem;

const set<string> STOP_WORDS = {"i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your", "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her", "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs", "themselves", "what", "which", "who", "whom", "this", "that", "these", "those", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or", "becuase", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once", "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"};

vector<fs::path> getPathNames(fs::path path) {

  vector<fs::path> pathNames;
  
  for(auto& p: fs::recursive_directory_iterator(path))
    if (is_regular_file(status(p)))
      pathNames.push_back(p.path());
  
  return pathNames;
  
}

int main() {

  vector<string> wordList;
  int command;
  ifstream inFile;
  string word;
  BST *bst = new BST;
  HashTable *hashTable;
  boost::timer t;
  double elapsedTime;
  
  for(const auto& pathName : getPathNames("hotels")) {
    inFile.open(pathName);
    if (!inFile) {
 
    }
    for (int i = 0; i < 25; i++) {
      inFile >> word;
      //while (inFile >> word) {
      for (unsigned int i = 0; i < word.size(); i++) {
	word[i] = tolower(word[i]);
	if (!isalpha(word[i])) {
	  word.erase(i, 1);
	  i--;
	}
      }
      if (STOP_WORDS.count(word) == 0 && word.size() > 0) {
	wordList.push_back(word); 
      }
    }
    inFile.close();
  }

 
  hashTable = new HashTable(wordList.size());

  for (string word : wordList) {
    bst->insert(word);
    hashTable->insert(word);
  }

  while (true) {
    cin >> command;

    switch(command) {
    case 1:
      {
	string wordToSearch;
	bool wordExists;
	cin >> wordToSearch;
	t.restart();
	wordExists = bst->search(wordToSearch);
	if (wordExists == true)
	  cout << "True" << endl;
	else
	  cout << "False" << endl;
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
      }
      break;
    case 2:
      {
	string wordToInsert;
	cin >> wordToInsert;
	t.restart();
	bst->insert(wordToInsert);
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
      }
      break;
    case 3:
      {
	string wordToDelete;
	cin >> wordToDelete;
	t.restart();
	bst->deleteWord(wordToDelete);
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
      }
      break;
    case 4:
      {
	t.restart();
	bst->sort();
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
      }
      break;
    case 5:
      {
	string startWord, endWord;
	cin >> startWord >> endWord;
	t.restart();
	bst->rangeSearch(startWord, endWord);
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
      }
    }
  }
  
  return 0;
  
}

