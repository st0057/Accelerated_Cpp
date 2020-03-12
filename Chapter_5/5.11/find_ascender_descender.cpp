#include <algorithm>
#include <iostream>
#include "find_ascender_descender.h"

using std::vector;      using std::string;
using std::endl;        using std::cout;
using std::cin;         using std::istream;

vector<string> ascenders{"b","d","f","h","k","l","t"};
vector<string> descenders{"g","j","p","q","y"};

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

vector<string> find_ascenders(vector<string>& dictionary)
{
  vector<string> ascender_words;

  for(vector<string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
  {
    for(vector<string>::iterator j = ascenders.begin(); j != ascenders.end(); ++j)
    {
      if (i->find(*j) != string::npos)
        ascender_words.push_back(*i);
    }
  }

  return ascender_words;
}

vector<string> find_descenders(vector<string>& dictionary)
{
  vector<string> descender_words;

for(vector<string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
  {
    for(vector<string>::iterator j = descenders.begin(); j != descenders.end(); ++j)
    {
      if (i->find(*j) != string::npos)
        descender_words.push_back(*i);
    }
  }

  return descender_words;
}

int main() {
  vector<string> dictionary, ascender_words, descender_words;

  read(cin, dictionary);

  ascender_words = find_ascenders(dictionary);
  descender_words = find_descenders(dictionary);

  cout << "-----Ascender Words-----" << endl;
  for (vector<string>::iterator i = ascender_words.begin(); i != ascender_words.end(); ++i)
  {
    cout << *i  << endl;
  }

  cout << "-----Descender Words-----" << endl;
  for (vector<string>::iterator i = descender_words.begin(); i != descender_words.end(); ++i)
  {
    cout << *i  << endl;
  }

  return 0;
}