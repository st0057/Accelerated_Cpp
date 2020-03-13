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
  vector<string>::size_type i = 0, j = 0;

  // continue until we've seen all rows from both pictures
  while (i != left.size() || j != right.size()) {
    // construct new string to hold characters from both pics
    string s;

    // copy a row from the left-hand side, if there is one
    if (i != left.size())
      s = left[i++];

    // pad to full width
    s += string(width1 - s.size(), ' ');

    // copy a row from the right hand side, if there is one
    if (j != right.size())
      s += right[j++];

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
  for (vector<string>::size_type i = 0; i != v.size(); ++i) {
    ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
  }

  // write the bottom border
  ret.push_back(border);
  return ret;
}

// Center function added by problem 5.5
vector<string> center(const vector<string>& picture)
{
  vector<string> new_picture;
  vector<string>::size_type max_length = 0;

  for (vector<string>::const_iterator i = picture.begin(); i != picture.end(); ++i)
  {
    if (i->size() > max_length)
      max_length = i->size();
  }

  for (vector<string>::const_iterator j = picture.begin(); j != picture.end(); ++j)
  {

    vector<string>::size_type padding = (max_length - j->size()) / 2;

    string new_line(padding, ' ');
    new_line += *j;
    new_picture.push_back(new_line);
  }

  return new_picture;
}

// Used for testing this function
int main() {
  vector<string> abc, abc1, abc_vcat, abc_hcat, abc_vcat_framed, abc_hcat_framed, picture;

  abc.push_back("abc");
  abc.push_back("bcd");
  abc1.push_back("cdef");
  abc1.push_back("cdef");

  picture.push_back("*");
  picture.push_back("***");
  picture.push_back("*****");

  vector<string> new_picture = center(picture);

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

  for (vector<string>::const_iterator i = new_picture.begin(); i != new_picture.end(); ++i) {
    cout << *i << endl;
  }

  return 0;
}