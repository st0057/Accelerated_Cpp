#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::vector;  using std::string;

int main()
{
  vector<string> test(10, "abc");
  string test2 = accumulate(test.begin(), test.end(), string(""));

  std::cout << test2 << std::endl;

  return 0;
}