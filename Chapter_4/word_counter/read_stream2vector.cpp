#include "read_stream2vector.h"
         
using std::string;         
using std::vector;
using std::istream;

int read(istream& is, vector<string>& v)
{
  string s;
  // read and store the word into a vector
  while (is >> s) {
    //cout << "arf" << endl;
    v.push_back(s);
  }
  is.clear();
  
  return 0;
}
