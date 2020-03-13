#include <algorithm>
#include <iostream>
#include "find_ascender_descender.h"

using std::vector;      using std::string;
using std::endl;        using std::cout;
using std::cin;         using std::istream;
using std::sort; 

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

vector<string> find_ascenders(vector<string>& dictionary, vector<string>& non_a_words)
{
  sort(dictionary.begin(), dictionary.end());
  vector<string> ascender_words;

  for(vector<string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
  {
    for(vector<string>::iterator j = ascenders.begin(); j != ascenders.end(); ++j)
    {
      if ((i->find(*j) != string::npos) && !(std::binary_search(ascender_words.begin(), ascender_words.end(), *i))) {
        ascender_words.push_back(*i);
      }
    }
  }

  non_a_words = find_unique_vector_items(dictionary, ascender_words);

  return ascender_words;
}

vector<string> find_descenders(vector<string>& dictionary, vector<string>& non_d_words)
{
  sort(dictionary.begin(), dictionary.end());
  vector<string> descender_words;

  for(vector<string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
    {
      for(vector<string>::iterator j = descenders.begin(); j != descenders.end(); ++j)
      {
        if ((i->find(*j) != string::npos) && !(std::binary_search(descender_words.begin(), descender_words.end(), *i))) {
        descender_words.push_back(*i);
      }
      }
    }

  non_d_words = find_unique_vector_items(dictionary, descender_words);

  return descender_words;
}

vector<string> find_unique_vector_items(vector<string>& v1, vector<string>& v2)
{
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  vector<string> v3(v1.size() + v2.size());
  vector<string>::iterator it;

  it = std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
  v3.resize(it-v3.begin());

  return v3;
}

vector<string> find_common_vector_items(vector<string>& v1, vector<string>& v2)
{
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  vector<string> v3;

  std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

  return v3;
}

int main() {
  vector<string> dictionary, ascender_words, descender_words, non_ascender_words, non_descender_words, neither;
  string::size_type biggest_non_count = 0;
  string biggest_non;

  read(cin, dictionary);

  ascender_words = find_ascenders(dictionary, non_ascender_words);
  descender_words = find_descenders(dictionary, non_descender_words);
  neither = find_common_vector_items(non_ascender_words, non_descender_words);

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

  cout << "-----Words With Neither-----" << endl;
  for (vector<string>::iterator i = neither.begin(); i != neither.end(); ++i)
  {
    if (biggest_non_count < i->size()){
      biggest_non_count = i->size();
      biggest_non = *i;
    }
    cout << *i  << endl;
  }

  cout << "Longest word w/o asc. or des. is: "  << biggest_non << endl;

  return 0;
}