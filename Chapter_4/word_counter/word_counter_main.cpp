#include <iostream>
#include <string>
#include <vector>
#include "read_stream2vector.h"
#include "distinct_word_counter.h"

using std::cin;     using std::sort;
using std::string;  using std::vector;

int main() {
  typedef vector<double>::size_type vec_sz;
  vector<string> words;

  // read strings into a vector of strings
  read(cin, words);

  // count the total number of words 
  vec_sz total = words.size();

  // count distinct number of words 
  vector<string> count_vector = distinct_words(words);

  // print the results
  for (int i = 0; i < total; i++) {
    cout << count_vector[i] << endl;
  }

  return 0;
}