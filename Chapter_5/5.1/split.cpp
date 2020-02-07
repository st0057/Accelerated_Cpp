#include <iostream>
#include "split.h"

using std::string;  using std::endl;
using std::vector;  using std::cout;
using std::list;

vector<string> split_vec(const string& s)
{
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  while (i != s.size()) {
    // ignore leading blanks 
    while (i != s.size() && isspace(s[i]))
      ++i;
    
    // find end of next word 
    string_size j = i;
    while(j != s.size() && !isspace(s[j]))
      ++j;

    // if we found some nonwhitespace characters 
    if (i != j) {
      // copy from s starting at i and ending at j-i 
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  return ret;
}

list<string> split_list(const string& s)
{
  list<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  while (i != s.size()) {
    // ignore leading blanks 
    while (i != s.size() && isspace(s[i]))
      ++i;
    
    // find end of next word 
    string_size j = i;
    while(j != s.size() && !isspace(s[j]))
      ++j;

    // if we found some nonwhitespace characters 
    if (i != j) {
      // copy from s starting at i and ending at j-i 
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  return ret;
}

//Test function here
int main() {
  string abc = "Hello there boy!";
  vector<string> abc_vec;
  list<string> abc_list;
  
  abc_vec = split_vec(abc);
  abc_list = split_list(abc);
  list<string>::iterator iter = abc_list.begin();

  cout << endl;

  cout << abc_vec[0] << abc_vec[2] << endl;

  //cout << abc_list(iter) << abc_list(iter + 1) << abc_list(iter) << endl;

  return 0;
}