#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using std::vector;      using std::string;
using std::endl;        using std::cout;
using std::cin;         using std::isupper;

int main() {
  string myString;
  vector<string> myVector;

  cout << "Write a sentence with Upper and lowercase letters: "  << endl;
  while(cin >> myString)
    myVector.push_back(myString);

  for (vector<string>::iterator i = myVector.begin(); i != myVector.end(); ++i){
    if (!isupper((*i)[0]))
      cout << (*i)[0] << "It's not upper case!" << endl;
      myVector.begin() = i;
  }

  for (vector<string>::iterator i = myVector.begin(); i != myVector.end(); ++i){
    cout << *i << " ";
  }
  cout << endl;

  return 0;
}