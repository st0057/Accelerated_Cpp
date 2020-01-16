#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::setw;    using std::cout;
using std::endl;    using std::string;
using std::to_string;

int main() {
  int maxlen = to_string(99 * 99).length();
  double i = 0.5;

  while(i < 100) {
    if (i < 10)
      cout << " " << i << setw(maxlen*2) << i * i << endl;
    else
      cout << i << setw(maxlen*2) << i * i << endl;
    
    i++;
  }

  return 0;
}