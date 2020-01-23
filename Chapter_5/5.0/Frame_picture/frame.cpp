#include <iostream>
#include "frame.h"

using std::string;    using std::vector;
using std::cout;      using std::endl;

vector<string> frame(const vector<string>& v)
{
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');

  // write the top border
  ret.push_back(border);

  //write each interior row, bordered by an asterisk and a space
  for (vector<string>::size_type i = 0; i != v.size(); ++i) {
    ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
  }

  // write the bottom border
  ret.push_back(border);
  return ret;
}


// Used for testing this function
// int main() {
//   vector<string> abc, abc_framed;

//   abc.push_back("abc");
//   abc.push_back("bcd");
//   abc.push_back("cdefg");

//   abc_framed = frame(abc);

//   for (vector<string>::size_type i = 0; i != abc_framed.size(); ++i) {
//     cout << abc_framed[i] << endl;
//   }

//   return 0;
// }