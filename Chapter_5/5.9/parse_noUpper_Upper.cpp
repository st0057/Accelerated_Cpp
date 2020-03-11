#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using std::vector;      using std::string;
using std::endl;        using std::cout;
using std::cin;         using std::isupper;

int main() {
  string myString;
  vector<string> myVector, uc_vec;

  cout << "Write a sentence with Upper and lowercase letters: "  << endl;
  while(cin >> myString)
    myVector.push_back(myString);
  int j = 0;
  for (vector<string>::size_type i = 0; i != myVector.size(); ++i){
    if (!isupper(myVector[i][0])){
      cout << myVector[i] << " ";
    }
    else
      uc_vec.push_back(myVector[i]);
  }

  for (vector<string>::iterator i = uc_vec.begin(); i != uc_vec.end(); ++i){
    cout << *i << " ";
  }
  cout << endl;

  return 0;
}