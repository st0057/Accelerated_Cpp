#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "extract_fails_ver1.h"

using std::cin;           using std::setprecision;
using std::cout;          using std::sort;
using std::domain_error;   using std::streamsize;
using std::endl;          using std::string;
using std::max;           using std::vector;

int main() {
  vector<Student_info> students;
  vector<Student_info> fails;
  Student_info record;
  string::size_type maxlen = 0;

  // read and store all student data
  while (read(cin, record)) {
    // find length of longest name
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // Extract the failing grades
  fails = extract_fails(students);

  cout << fails[0].name << "  " << grade(fails[0]) << endl;

  return 0;
}