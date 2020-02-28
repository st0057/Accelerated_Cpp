#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "split.h"
#include "permuted_index.h"

using std::string;      using std::vector;
using std::endl;        using std::cout;
using std::sort;        using std::tolower;

const string endmark = "<ENDMARK>";

// Function to rotate the index one place to the left
void rotate_left(vector<string>& vec)
{
  vec.push_back(vec[0]);
  vec.erase(vec.begin());  
}

// Function to rotate the index one place to the right
void rotate_right(vector<string>& vec)
{
  string end = *(vec.rbegin());
  vec.pop_back();
  vec.insert(vec.begin(), end);  
}

// Function to vertically concatenate two vector<string>'s
vector<string> vcat(vector<string>& top, const vector<string>& bottom)
{
  // copy the top picture
  vector<string> ret = top;

  // copy entire bottom picture
  ret.insert(ret.end(), bottom.begin(), bottom.end());

  return ret;
}

// Function to create a permutation of a vector of a vector of strings
vector<vector<string>> permute_vec(vector<string>& vec)
{
  // Get the original vector length
  vector<string>::size_type vec_length = vec.size();
  // initialize the permuted vector
  vector<string> shifted_vec = vec;
  vector<vector<string>> perm_vec;
  perm_vec.resize(vec_length - 1);

  for (vector<vector<string>>::iterator iter = perm_vec.begin(); iter != perm_vec.end(); iter++)
  {
    if(shifted_vec[0] != endmark){
      //cout << shifted_vec[0] << endl;
      *iter = shifted_vec;
      rotate_left(shifted_vec);
    }
  }

  return perm_vec;
}

// Bool func that compares the lowercase char of the first string in a vector<string>
 bool compare (vector<string> i, vector<string> j) {
    //cout << i[0] << " " << j[0] << endl;
    return (i[0] < j[0]); 
   }

// For testing
int main() {
  vector<string> s1_vec, s2_vec;
  string s1 = "The quick brown fox";
  string s2 = "jumped over the fence";

  s1 = s1 + " " + endmark;
  s2 = s2 + " " + endmark;
  
  s1_vec = split_vec(s1);
  s2_vec = split_vec(s2);

  vector<string>::size_type len_s1_vec = s1_vec.size();

  cout << "Permuting vector..." << endl;

  vector<vector<string>> permuted_vector = permute_vec(s1_vec);

  vector<vector<string>>::size_type len_perm_vec = permuted_vector.size();

  cout << "Sorting permutations..." << len_s1_vec << endl;

  sort(permuted_vector.begin(), permuted_vector.end(), compare);

  cout << "Permuations sorted!!!" << endl;

  for (vector<string>::size_type i = 0; i < len_perm_vec; ++i){
    //cout << "i=" << i << endl;
    //cout << permuted_vector[i](permuted_vector[i].begin()) << endl;
    // while (*iter != endmark){
    //   cout << "rotating right" << endl;
    //   rotate_right(permuted_vector[i]);
    // }
    for (vector<string>::size_type j = 0; j < len_s1_vec; ++j){
      if (permuted_vector[i][j] != endmark) {
        if (j != len_s1_vec - 1)
          cout << permuted_vector[i][j] + " ";
        else
          cout << permuted_vector[i][j] << endl;
      }
      else {
        if (j == len_s1_vec - 1)
          cout << endl;
      }
    }
  }
}

