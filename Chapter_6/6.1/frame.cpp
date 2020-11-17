#include <iostream>
#include "frame.h"
#include "width.h"

using std::string;    using std::vector;
using std::cout;      using std::endl;

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
  vector<string> ret;

  // add 1 to leave a space between pictures
  string::size_type width1 = width(left) + 1;

  // indices to look at elements from left and right respectively
  vector<string>::const_iterator i = left.begin(), j = right.begin();

  // continue until we've seen all rows from both pictures
  while (i != left.end() || j != right.end()) {
    // construct new string to hold characters from both pics
    string s;

    // copy a row from the left-hand side, if there is one
    if (i != left.end())
      s = *i++;

    // pad to full width
    s += string(width1 - s.size(), ' ');

    // copy a row from the right hand side, if there is one
    if (j != right.end())
      s += *j++;

    // add s to the picture we're creating
    ret.push_back(s);
  }

  return ret;

}

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
  for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it) {
    ret.push_back("* " + *it + string(maxlen - (*it).size(), ' ') + " *");
  }

  // write the bottom border
  ret.push_back(border);
  return ret;
}


// Used for testing this function
int main() {
  vector<string> abc, abc1, abc_vcat, abc_hcat, abc_vcat_framed, abc_hcat_framed;

  abc.push_back("abc");
  abc.push_back("bcd");
  abc1.push_back("cdef");
  abc1.push_back("cdef");

  abc_vcat = vcat(abc, abc1);
  abc_hcat = hcat(abc, abc1);

  abc_vcat_framed = frame(abc_vcat);
  abc_hcat_framed = frame(abc_hcat);

  for (vector<string>::size_type i = 0; i != abc_vcat_framed.size(); ++i) {
    cout << abc_vcat_framed[i] << endl;
  }

  for (vector<string>::size_type i = 0; i != abc_hcat_framed.size(); ++i) {
    cout << abc_hcat_framed[i] << endl;
  }

  return 0;
}