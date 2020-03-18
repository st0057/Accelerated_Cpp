#include <algorithm>
#include "find_palindromes.h"

using std::vector;      using std::string;
using std::endl;        using std::cout;
using std::cin;         using std::reverse;
using std::istream;     using std::equal;

bool is_palindrome(const string& s)
{
  return equal(s.begin(), s.end(), s.rbegin());
}


istream& read(istream& in, vector<string>& vec)
{
  if (in) {
    // get rid of previous contents
    vec.clear();

    string x;
    while (in >> x)
      vec.push_back(x);

    // clear the stream so that input will work for the next student 
    in.clear();
  }
  return in;
}

vector<string> find_palindromes(vector<string>& dictionary)
{
  vector<string> palindromes;

  for(vector<string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
  {
    if (is_palindrome(*i))
      palindromes.push_back(*i);
  }

  return palindromes;
}

int main() {
  vector<string> dictionary, palindromes;

  read(cin, dictionary);

  palindromes = find_palindromes(dictionary);

  for (vector<string>::iterator i = palindromes.begin(); i != palindromes.end(); ++i)
  {
    cout << *i  << endl;
  }

  return 0;
}