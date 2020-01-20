#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#inlcude "extract_fails_ver1.h"

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

  fails = extract_fails(vector<Student_info>& students);

  // write the names and grades
  for (vector<Student_info>::size_type i = 0; i != fails.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 chars
    cout << fails[i].name << string(maxlen + 1 - fails[i].name.size(), ' ');

    // compute and write the grade 
    try {
      streamsize prec = cout.precision();
      cout << setprecision(3) << fails[i].final_grade << setprecision(prec);
    } catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  return 0;
}