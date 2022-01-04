#include <iostream>
using std::cout;      using std::endl;

int main() {
  int i = 0;

  int j = i++;
  cout << "j = " << j << endl;
  cout << "i = " << i << endl;

  j = ++i;
  cout << "j = " << j << endl;
  cout << "i = " << i << endl;

  return 0;
}