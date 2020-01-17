#include <algorithm>
#include <sstream>
#include "distinct_word_counter.h"

using std::cin;           using std::cout;
using std::endl;          using std::sort;
using std::stringstream;  using std::string;    
using std::vector;

int distinct_words(vector<string> words, vector<string>& count_vector) {
  typedef vector<double>::size_type vec_sz;
  string temporary;
  stringstream ss;
  int j;
  int i = 0;

  // count the number of words
  vec_sz length = words.size();

  // Check that user entered at least one word 
  if (length == 0){
    cout << endl << "You must enter at least one word!" << endl;

    return 1;
  }

  // sort the words alphabetically
  sort(words.begin(), words.end());

  // count number of times a word occurs
  while(i < length){
    j = 1;
    ss.str("");
    if (i != length) {
      while (words[i] == words[i + j]) {
        j++;
      }
    }
    ss << j;
    temporary = words[i] + " " + ss.str();
    count_vector.push_back(temporary);
    if (j == 1)
      i++;
    else 
      i = i + j;
  }

  return 0;
}