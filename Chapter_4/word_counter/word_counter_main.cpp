#include <iostream>
#include <string>
#include <vector>
#include "read_stream2vector.h"

using std::cin;     using std::sort;
using std::string;  using std::vector;

int main() {
  typedef vector<double>::size_type vec_sz;
  vector<string> words;

  // read strings into a vector of strings
  read(cin, words);

  // count the number of words
  vec_sz length = words.size();

  // Check that user entered at least one word 
  if (size == 0){
    cout << endl << "You must enter at least one word!" << endl;

    return 1;
  }

  // sort the words alphabetically
  sort(words.begin(), words.end())

  // count number of times a word occurs
  for (int i = 0; i < length; i++) {
    
  }


  return 0;
}