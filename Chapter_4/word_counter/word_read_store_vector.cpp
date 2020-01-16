#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;           using std::setprecision;
using std::cout;          using std::sort;
using std::domain_error;   using std::streamsize;
using std::endl;          using std::string;
using std::max;           using std::vector;
using std::istream;

istream& read(istream& is, string& s)
{
  // read and store the word into a string
  is >> s;

  return is;
}

int read(istream& is, vector<string>& v)
{
  string s;
  // read and store the word into a vector
  while (is) {
    is >> s;
    cout << "arf" << endl;
    v.push_back(s);
  }

  return 0;
}

int main() {
  vector<string> words;
  typedef vector<double>::size_type vec_sz;
  
  // read and store all words into a vector
  read(cin, words);

  vec_sz maxlen = words.size();
  cout << maxlen << endl;
  for (int i = 0; i < maxlen; i++){
    cout << words[i] << endl;
  }
  return 0;
}