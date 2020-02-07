#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "split.h"
#include "permuted_index.h"

using std::string;      using std::vector;
using std::endl;        using std::cout;

vector<string> shift_vec_index_left(vector<string>& vec)
{
  vec.push_back(vec[0]);
  vec.erase(vec.begin());  

  return vec;
}

vector<string> vcat(vector<string>& top, const vector<string>& bottom)
{
  // copy the top picture
  vector<string> ret = top;

  // copy entire bottom picture
  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

vector<string> permute_vec(vector<string>& vec)
{
  // Get the original vector length
  vector<string>::size_type vec_length = vec.size();
  // initialize the permuted vector
  vector<string> shifted_vec = vec, perm_vec;

  for (int i = 0; i < vec_length; i++) {
    perm_vec = vcat(perm_vec, shifted_vec);
    shifted_vec = shift_vec_index_left(shifted_vec);
  }

  return perm_vec;
}

int main() {
  vector<string> s1_vec, s2_vec;
  string s1 = "The quick brown fox";
  string s2 = "jumped over the fence";

  s1_vec = split_vec(s1);
  s2_vec = split_vec(s2);

  vector<string>::size_type len_s1_vec = s1_vec.size();

  vector<string> permuted_vector = permute_vec(s1_vec);

  vector<string>::size_type len_perm_vec = permuted_vector.size();
  for (vector<string>::size_type i = 0; i < len_perm_vec; ++i){
    if ((i + 1) % len_s1_vec != 0)
      cout << permuted_vector[i] + " ";
    else
      cout << permuted_vector[i] << endl;
  }
}