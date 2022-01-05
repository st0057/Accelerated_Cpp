#include <iterator>
#include <iostream>
#include "vcat.h"

using std::vector;        using std::string;
using std::back_inserter; using std::copy;
using std::cout;          using std::endl;

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
  // copy the top picture
  vector<string> ret = top;

  // copy entire bottom picture
  copy(bottom.begin(), bottom.end(), back_inserter(ret));

  return ret;
}

// Test the code
// int main () {
//   vector<string> abc, abc1, abc_vcat;

//   abc.push_back("abc");
//   abc.push_back("bcd");
//   abc1.push_back("cdef");
//   abc1.push_back("cdef");

//   abc_vcat = vcat(abc, abc1);

//   for (vector<string>::size_type i = 0; i != abc_vcat.size(); ++i) {
//     cout << abc_vcat[i] << endl;
//   }

//   return 0;
// }