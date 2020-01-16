#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;           using std::setprecision;
using std::cout;          using std::sort;
using std::domain_error;   using std::streamsize;
using std::endl;          using std::string;
using std::max;           using std::vector;

int main() {
  vector<string> words;
  string::size_type maxlen = 0;

  // read and store all words
  while (read(cin, words)) {
    // find length of longest word
    maxlen = max(maxlen, words.name.size());
    students.push_back(words);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 chars
    cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the grade 
    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }
  return 0;
}