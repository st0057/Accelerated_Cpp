#include <algorithm>
#include <numeric>
#include <vector>
#include "average.h"

using std::vector;

double average(const vector<double>& v)
{
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}