#include "read_grammar.h"

using std::string;  using std::vector;
using std::istream;

Grammar read_grammar(istream& in)
{
  Grammar ret;
  string line;

  // read the input
  while (getline(in, line))
  {
    // split the input into words
    vector<string> entry = split(line);

    if (!entry.empty())
    {
      // use the category to store the associated rule
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
  }
  return ret;
}