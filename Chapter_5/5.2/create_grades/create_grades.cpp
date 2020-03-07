#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using std::vector;    using std::string;
using std::cout;      using std::cin;
using std::ofstream;  using std::endl;
using std::to_string;

int main() {
  string names = "John";

  int number = 1;

  cout << "How many lines of grades should I generate?" << endl;
  cin >> number;

  ofstream fs("grades" + to_string(number) + ".txt");

  if(!fs)
    {
        std::cerr<<"Cannot open the output file."<<std::endl;
        return 1;
    }

  for (int i = 0; i != number; ++i) {
    fs << names << " " << rand() % 100 << " " << rand() % 100 << " " << rand() % 100 << " " << rand() % 100 << endl;
  }

  fs.close();

  return 0;

}