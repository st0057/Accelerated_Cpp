#include <iostream>
#include <string>
#include <vector>
#include "read_stream2vector.h"
#include "distinct_word_counter.h"

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::vector;

int main() {
  typedef vector<double>::size_type vec_sz;
  vector<string> words;
  vector<string> count_vector;

  // read strings into a vector of strings
  read(cin, words);

  // count the total number of words 
  vec_sz total = words.size();

  // count distinct number of words 
  distinct_words(words, count_vector);
  vec_sz num_distinct = count_vector.size();

  // print the results
  for (int i = 0; i < num_distinct; i++) {
    cout << count_vector[i] << endl;
  }

  return 0;
}