#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <experimental/filesystem>
#include <fstream>
<<<<<<< HEAD

#include "bst.h"
=======
#include <boost/timer.hpp>
#include "bst.h"
#include "hashTable.h"
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e

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

<<<<<<< HEAD
=======
  vector<string> wordList;
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
  int command;
  ifstream inFile;
  string word;
  BST *bst = new BST;
<<<<<<< HEAD
=======
  HashTable *hashTable;
  boost::timer t;
  double elapsedTime;
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
  
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
<<<<<<< HEAD
		bst->insert(word); 
=======
	wordList.push_back(word); 
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
      }
    }
    inFile.close();
  }

<<<<<<< HEAD
  bst->printInorder();

  cout << "number of words: " << bst->countWords() << endl;

  while (true) {
    cout << "Enter a command (1-search, 2-insert, 3-delete, 4-sort, 5-range search):" << endl;
=======
 
  hashTable = new HashTable(wordList.size());

  for (string word : wordList) {
    bst->insert(word);
    hashTable->insert(word);
  }

  while (true) {
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
    cin >> command;

    switch(command) {
    case 1:
      {
	string wordToSearch;
	bool wordExists;
<<<<<<< HEAD
	cout << "Enter a word to search: ";
	cin >> wordToSearch;
=======
	cin >> wordToSearch;
	t.restart();
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
	wordExists = bst->search(wordToSearch);
	if (wordExists == true)
	  cout << "True" << endl;
	else
	  cout << "False" << endl;
<<<<<<< HEAD
=======
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
      }
      break;
    case 2:
      {
	string wordToInsert;
<<<<<<< HEAD
	cout << "Enter a word to insert: ";
	cin >> wordToInsert;
	bst->insert(wordToInsert);
=======
	cin >> wordToInsert;
	t.restart();
	bst->insert(wordToInsert);
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
      }
      break;
    case 3:
      {
	string wordToDelete;
<<<<<<< HEAD
	cout << "Enter a word to delete: ";
	cin >> wordToDelete;
	bst->deleteWord(wordToDelete);
=======
	cin >> wordToDelete;
	t.restart();
	bst->deleteWord(wordToDelete);
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
      }
      break;
    case 4:
      {
<<<<<<< HEAD
	bst->sort();
=======
	t.restart();
	bst->sort();
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
      }
      break;
    case 5:
      {
	string startWord, endWord;
<<<<<<< HEAD
	cout << "Enter the start word and end word, separated by a space: ";
	cin >> startWord >> endWord;
	bst->rangeSearch(startWord, endWord);
=======
	cin >> startWord >> endWord;
	t.restart();
	bst->rangeSearch(startWord, endWord);
	elapsedTime = t.elapsed();
	cout << fixed << "BST: " << elapsedTime << endl;
>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
      }
    }
  }
  
  return 0;
  
<<<<<<< HEAD
}
=======
}

>>>>>>> 1cc8c21a5baba20807632831861ab17ea28d5e2e
