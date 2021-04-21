#include <cctype>
#include "find_urls.h"

using std::vector;        using std::string;
using std::endl;          using std::cout;
using std::cin;           

// Test code
int main() {
  vector<string> urls;
  string dictionary;

  read(cin, dictionary);

  urls = find_urls(dictionary);

  for (vector<string>::iterator i = urls.begin(); i != urls.end(); ++i)
  {
    cout << *i  << endl;
  }

  return 0;
}