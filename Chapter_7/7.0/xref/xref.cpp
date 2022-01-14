#include "xref.h"

using std::string;  using std::map;
using std::vector;  using std::istream;

map<string, vector<int> >
xref(istream& in, vector<string> find_words(const string&)) // NOTE CAN'T DEFAULT IN .cpp and .h
{
  string line;
  int line_number = 0;
  map<string, vector<int> > ret;  // map string to vector<int>
 
  // Read the next line
  while (getline(in, line)) {
    ++line_number;
 
    // Break the input line into words
    vector<string> words = find_words(line);
 
    // remember that each word occurs on the current line
    for (vector<string>::const_iterator it = words.begin();
         it != words.end(); ++it)
      ret[*it].push_back(line_number);
  }
 
  return ret;
}