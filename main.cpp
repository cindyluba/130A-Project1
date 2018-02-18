#include <iostream>
#include <string>
#include <vector>
#include <experimental/filesystem>
#include <fstream>

#include "bst.h"

using namespace std;

namespace fs = experimental::filesystem;

const int ALPHA_START = 97, ALPHA_END = 122;

vector<fs::path> getPathNames(fs::path path) {

  vector<fs::path> pathNames;
  
  for(auto& p: fs::recursive_directory_iterator(path))
    if (is_regular_file(status(p)))
      pathNames.push_back(p.path());
  
  return pathNames;
  
}

int main() {

  ifstream inFile;
  string word;
  BST *bst = new BST();
  
  for(const auto& pathName : getPathNames("hotels")) {
    inFile.open(pathName);
    if (!inFile) {

    }
    while (inFile >> word) {
      for (int i = 0; i < word.size(); i++) {
	word[i] = tolower(word[i]);
	if ((int)word[i] >= ALPHA_START || (int)word[i] <= ALPHA_END) {
	    bst->insert(word);
	  }
      }
    }
    inFile.close();
  }

    return 0;
  
}

