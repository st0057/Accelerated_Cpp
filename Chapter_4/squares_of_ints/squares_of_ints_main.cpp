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

  for (int i = 0; i < 100; i++){
    if (i < 10)
      cout << " " << i << setw(maxlen*2) << i * i << endl;
    else
      cout << i << setw(maxlen*2) << i * i << endl;
  }

  return 0;
}