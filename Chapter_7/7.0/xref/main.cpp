#include <iostream>   // std::cin, std::cout, std::endl
#include <map>        // std::map
#include <string>     // std::string
#include <vector>     // std::vector
#include "xref.h"     // xref
 
using std::cin;     using std::cout;
using std::endl;    using std::map;
using std::string;  using std::vector;

int main()
{
  // Call xref using split by default.
  map<string, vector<int> > ret = xref(cin);
 
  // Write the results.
  for (map<string, vector<int> >::const_iterator it = ret.begin();
       it != ret.end(); ++it) {
 
    // Write the word
    cout << it->first << " occurs on line(s): ";
 
    // Followed by one or more line numbers.
    vector<int>::const_iterator line_it = it->second.begin();
    cout << *line_it;   // write the first line number
 
    ++line_it;
    // Write the rest of the line numbers, if any.
    while (line_it != it->second.end()) {
      cout << ", " << *line_it;
      ++line_it;
    }
    // Write a new line to separate each word from the next.
    cout << endl;
  }
 
  return 0;
}