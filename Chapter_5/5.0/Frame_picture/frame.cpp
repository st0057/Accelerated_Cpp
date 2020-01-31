#include <iostream>
#include "frame.h"
#include "width.h"

using std::string;    using std::vector;
using std::cout;      using std::endl;

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
  // copy the top picture
  vector<string> ret = top;

  // copy entire bottom picture
  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

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
int main() {
  vector<string> abc, abc1, abc_cat, abc_cat_framed;

  abc.push_back("abc");
  abc.push_back("bcd");
  abc1.push_back("cdef");
  abc1.push_back("cdef");

  abc_cat = vcat(abc, abc1);

  abc_cat_framed = frame(abc_cat);

  for (vector<string>::size_type i = 0; i != abc_cat_framed.size(); ++i) {
    cout << abc_cat_framed[i] << endl;
  }

  return 0;
}