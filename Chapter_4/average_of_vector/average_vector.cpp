#include <iostream>
#include <string>
#include <vector>
#include "average_vector.h"

using std::vector; using std::endl;
using std::cout;

int average_vect(vector<double>& v, double& ave){
  typedef vector<double>::size_type vec_sz;
  float sum = 0.0;
  vec_sz size = v.size();

  if (size == 0) {
    cout << endl << "Must have at least 1 item in vector." << endl;
    return 1;
  }

  for (int i = 0; i < size; i++)
    sum = sum + v[i];
  
  ave = sum / size;

  return 0;
}

int main() {
  vector<double> a;
  double b;
  a.push_back(1.5);
  a.push_back(2);
  //a.push_back(2.0);
  average_vect(a, b);
  cout << b << endl;

  return 0;
}