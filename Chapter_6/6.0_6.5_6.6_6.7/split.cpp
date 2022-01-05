#include <algorithm>
#include <iostream>
#include "split.h"

using std::string;  using std::endl;
using std::vector;  using std::cout;
using std::find_if;

// true if the argument is whitespace, false otherwise
bool space(char c)
{
  return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
  return !isspace(c);
}

vector<string> split(const string& str)
{
  typedef string::const_iterator iter;
  vector<string> ret;

  iter i = str.begin();
  while (i != str.end()) {
    // ignore leading blanks 
    i = find_if(i, str.end(), not_space);
    
    // find end of next word 
    iter j = find_if(i, str.end(), space);

    // copy the characters in [i, j) 
    if (i != str.end())
      ret.push_back(string(i, j));
    i = j;
  }
  return ret;
}

//Test function here
// int main() {
//   string abc = "Hello there boy!";
//   vector<string> abc_vec;

//   abc_vec = split(abc);

//   cout << endl;

//   cout << abc_vec[0] << abc_vec[2] << endl;

//   return 0;
// }